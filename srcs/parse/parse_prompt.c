/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:40:44 by fraalmei          #+#    #+#             */
/*   Updated: 2023/08/28 11:13:34 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	num_prom(t_prompt *prom)
{
	int	i;

	i = 1;
	while (prom->next)
	{
		i++;
		prom = prom->next;
	}
	return (i);
}

static int	check_start_prom(char *buffer, t_prompt *prom)
{
	if (prom != NULL && is_pipe(buffer) > 0)
		return (1);
	return (0);
}

static int	check_end_prom(char *buffer)
{
	if (is_redir(buffer) > 0 && !buffer[2])
		return (1);
	return (0);
}

/* static void	end_prom(char *buffer, t_prompt *prom, t_prompt *swap, int *i)
{
	if (!prom && is_redirecction(&buffer[*i]) > 0)
	{
		swap->sep1 = ft_chr_n_join(swap->sep1, \
			&buffer[*i], is_redirecction(&buffer[*i]));
		*i += is_redirecction(&buffer[*i]);
		swap->n_arguments = ft_str_strlen(swap->arguments);
		prom = swap;
	}
	else if (is_redirecction(&buffer[*i]) > 0)
	{
		swap->sep1 = ft_chr_n_join(swap->sep1, \
			&buffer[*i], is_redirecction(&buffer[*i]));
		i += is_redirecction(&buffer[*i]);
		swap->n_arguments = ft_str_strlen(swap->arguments);
		last_prom(prom)->next = swap;
		swap->prev = last_prom(prom);
	}
	else if (!prom)
	{
		if (swap->arguments)
			swap->n_arguments = ft_str_strlen(swap->arguments);
		else
			swap->n_arguments = 0;
		prom = swap;
	}
	else
	{
		if (swap->arguments)
			swap->n_arguments = ft_str_strlen(swap->arguments);
		else
			swap->n_arguments = 0;
		last_prom(prom)->next = swap;
		swap->prev = last_prom(prom);
	}
} */

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
		if (check_start_prom(&buffer[0], prom) != 0)
			return (free_prompt(prom), free_prompt (swap), write(1, "syntax error near unexpected token ", 36), write(1, &buffer[0], is_pipe(&buffer[i])), write(1, "\n", 1), NULL);
		else if (!swap->command[0] && buffer[i] != ' ' && is_redirecction(&buffer[i]) == 0)
		{
			swap->command[0] = read_word(buffer, &i);
			if (swap->command[0] == NULL)
				return (free (prom), NULL);
			i++;
			while (buffer[i] == ' ')
				i++;
			if (buffer[i] == '-')
				swap->n_options = option_gen(swap, buffer, &i);
			else
				i--;
		}
		else if (buffer[i] != ' ' && is_redirecction(&buffer[i]) == 0)
		{
			swap->arguments = str_strjoin_freeall(swap->arguments, read_word(buffer, &i));
		}
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
				swap->n_arguments = ft_str_strlen(swap->arguments);
				last_prom(prom)->next = swap;
				swap->prev = last_prom(prom);
			}
			swap = make_prompt_struct();
			swap->sep0 = last_prom(prom)->sep1;
			i--;
		}
		if (check_end_prom(&buffer[i]) != 0)
			return (free_prompt(prom), free_prompt (swap), write(1, "syntax error near unexpected token `newline'\n", 46), NULL);
		i++;
		//printf("veamos cuanto pasa por aqui %i\n", i);
	}
	if (!prom)
	{
		if (swap->arguments)
			swap->n_arguments = ft_str_strlen(swap->arguments);
		else
			swap->n_arguments = 0;
		prom = swap;
	}
	else
	{
		if (swap->arguments)
			swap->n_arguments = ft_str_strlen(swap->arguments);
		else
			swap->n_arguments = 0;
		last_prom(prom)->next = swap;
		swap->prev = last_prom(prom);
	}
	g_ms->n_prompts = num_prom(prom);
	return (prom);
}
