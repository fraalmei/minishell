/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:40:44 by fraalmei          #+#    #+#             */
/*   Updated: 2023/09/15 11:20:45 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	check_start_prom(char *buffer, t_prompt *prom)
{
	if (prom != NULL && is_pipe(buffer) > 0)
		return (1);
	return (0);
}

static void	get_option_args(char *buffer, int *i, t_prompt *swap)
{
	if ((buffer[*i] == '-') && (buffer[*i + 1] != ' ') && !swap->arguments[2])
		swap->n_options = option_gen(swap, buffer, i);
	else
		swap->arguments = \
			str_strjoin_freeall(swap->arguments, read_word(buffer, i));
}

static t_prompt	*add_prompt(t_prompt *prom, t_prompt *swap)
{
	if (swap->arguments)
		swap->n_arguments = ft_str_strlen(swap->arguments);
	else
		swap->n_arguments = 0;
	if (swap->n_options > 0)
		swap->n_arguments -= 1;
	if (!prom)
		return (swap);
	else
	{
		last_prom(prom)->next = swap;
		swap->prev = last_prom(prom);
	}
	g_ms->n_prompts = num_prom(prom);
	return (prom);
}

t_prompt	*buffer_to_prompt(char *buffer, t_prompt *prom)
{
	t_prompt	*swap;
	int			i;

	i = 0;
	if (check_quotes(buffer))
		return (printf("Comillas abiertas\n"), NULL);
	swap = make_prompt_struct();
	if (!swap)
		return (NULL);
	while (buffer[i])
	{
		if (g_ms->signals->status_code != 0)
			return (free_prompt(prom), free_prompt(swap), NULL);
		if (check_start_prom(&buffer[0], prom) != 0)
			return (free_prompt(prom), free_prompt (swap), write(1, \
				"syntax error near unexpected token ", 36), write(1, \
				&buffer[0], is_pipe(&buffer[i])), write(1, "\n", 1), NULL);
		else if (!swap->command && buffer[i] != ' ' && \
			is_redirecction(&buffer[i]) == 0)
		{
			swap->command = read_word(buffer, &i);
			swap->arguments[0] = ft_strdup(swap->command);
			if (swap->command == NULL)
				return (free (prom), NULL);
		}
		else if (buffer[i] != ' ' && is_redirecction(&buffer[i]) == 0)
			get_option_args(buffer, &i, swap);
		else if (buffer[i] != ' ' && is_redir(&buffer[i]) != 0)
			get_redir(buffer, &i, swap);
		else if (is_pipe(&buffer[i]) != 0)
		{
			if (!prom && is_pipe(&buffer[i]) > 0)
			{
				swap->sep1 = ft_chr_n_join(swap->sep1, \
					&buffer[i], is_pipe(&buffer[i]));
				i += is_pipe(&buffer[i]);
				swap->n_arguments = ft_str_strlen(swap->arguments);
				prom = swap;
			}
			else if (is_pipe(&buffer[i]) > 0)
			{
				swap->sep1 = ft_chr_n_join(swap->sep1, \
					&buffer[i], is_pipe(&buffer[i]));
				i += is_pipe(&buffer[i]);
				swap->n_arguments = ft_str_strlen(swap->arguments) - 1;
				last_prom(prom)->next = swap;
				swap->prev = last_prom(prom);
			}
			swap = make_prompt_struct();
			swap->sep0 = last_prom(prom)->sep1;
			i--;
		}
		if (check_end_prom(&buffer[i]) != 0)
			return (free_prompt(prom), free_prompt (swap), write(1, \
				"syntax error near unexpected token `newline'\n", 46), NULL);
		i++;
	}
	prom = add_prompt(prom, swap);
	return (prom);
}
