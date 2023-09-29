/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:40:44 by fraalmei          #+#    #+#             */
/*   Updated: 2023/09/29 17:57:57 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	add_last_prompt(t_prompt **prom, t_prompt *swap)
{
	if (swap->arguments)
		swap->n_arguments = ft_str_strlen(swap->arguments);
	else
		swap->n_arguments = 0;
	if (swap->n_options > 0)
		swap->n_arguments -= 1;
	if (!*prom)
		*prom = swap;
	else
	{
		last_prom(*prom)->next = swap;
		swap->prev = last_prom(*prom);
	}
	g_ms->n_prompts = num_prom(*prom);
}

static t_prompt	*add_prom(char *buff, t_prompt **prom, t_prompt *swap, int *i)
{
	if (!*prom && is_pipe(&buff[*i]) > 0)
	{
		swap->sep1 = ft_chr_n_join(swap->sep1, \
			&buff[*i], is_pipe(&buff[*i]));
		i += is_pipe(&buff[*i]);
		swap->n_arguments = ft_str_strlen(swap->arguments);
		*prom = swap;
		swap = NULL;
	}
	else if (is_pipe(&buff[*i]) > 0)
	{
		swap->sep1 = ft_chr_n_join(swap->sep1, \
			&buff[*i], is_pipe(&buff[*i]));
		i += is_pipe(&buff[*i]);
		swap->n_arguments = ft_str_strlen(swap->arguments) - 1;
		last_prom(*prom)->next = swap;
		swap->prev = last_prom(*prom);
	}
	swap = new_prompt_struct();
	swap->sep0 = last_prom(*prom)->sep1;
	swap->pos_p += last_prom(*prom)->pos_p;
	*i -= 1;
	return (swap);
}

static int	ride_buffer(char *buff, t_prompt **prom, t_prompt **swap, int *i)
{
	if (check_start_prom(&buff[0], *prom) != 0)
		return (free_prompt(*prom), free_prompt (*swap), write(1, \
			"syntax error near unexpected token ", 36), write(1, \
			&buff[0], is_pipe(&buff[*i])), write(1, "\n", 1), -1);
	if (!(*swap)->command && buff[*i] != ' ' && is_redirecction(&buff[*i]) == 0)
	{
		(*swap)->command = read_word(buff, i);
		(*swap)->arguments[0] = ft_strdup((*swap)->command);
		if ((*swap)->command == NULL)
			return (free (*prom), -1);
	}
	else if (buff[*i] != ' ' && is_redirecction(&buff[*i]) == 0)
		get_option_args(buff, i, *swap);
	else if (buff[*i] != ' ' && is_redir(&buff[*i]) != 0)
		get_redir(buff, i, *swap);
	else if (is_pipe(&buff[*i]) != 0)
		*swap = add_prom(buff, prom, *swap, i);
	if (check_end_prom(&buff[*i]) != 0)
		return (free_prompt(*prom), free_prompt (*swap), write(1, \
			"syntax error near unexpected token `newline'\n", 46), -1);
	*i += 1;
	return (0);
}

t_prompt	*buffer_to_prompt(char *buffer, t_prompt *prom)
{
	t_prompt	*swap;
	int			i;

	i = 0;
	if (check_quotes(buffer))
		return (printf("Comillas abiertas\n"), NULL);
	swap = new_prompt_struct();
	if (!swap)
		return (NULL);
	while (buffer[i])
	{
		if (g_ms->signals->status_code != 0)
			return (free_prompt(prom), free_prompt(swap), NULL);
		if (ride_buffer(buffer, &prom, &swap, &i))
			return (NULL);
		if (g_ms->signals->status_code != 0)
			return (free_prompt(prom), free_prompt(swap), NULL);
	}
	add_last_prompt(&prom, swap);
	return (prom);
}
		/* if (check_start_prom(&buffer[0], prom) != 0)
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
			swap = add_prom(buffer, &prom, swap, &i);
		if (check_end_prom(&buffer[i]) != 0)
			return (free_prompt(prom), free_prompt (swap), write(1, \
				"syntax error near unexpected token `newline'\n", 46), NULL);
		i++; */
