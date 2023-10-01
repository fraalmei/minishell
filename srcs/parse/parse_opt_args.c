/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opt_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:57:09 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/01 00:19:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_start_prom(char *buffer, t_prompt *prom)
{
	if (prom != NULL && is_pipe(buffer) > 0)
		return (1);
	return (0);
}

int	option_gen(t_prompt *prm, char *st, int *i)
{
	int		x[2];

	if (!prm->arguments[1])
	{
		prm->arguments[1] = (char *)ft_calloc(sizeof(char), 2);
		prm->arguments[1] = ft_chrjoin(prm->arguments[1], '-');
	}
	if (!prm->arguments[1])
		return (-1);
	x[0] = 0;
	x[1] = ft_strlen(prm->arguments[1]) - 1;
	while (st[*i] && is_redirecction(&st[*i]) == 0 && st[*i] != ' ')
	{
		if (st[*i] == '-' && x[0] < 1)
			x[0]++;
		else if (x[0] > 1)
		{
			g_ms->signals->error_status = 1;
			return (print_error(NULL, 6), -1);
		}
		else if (!ft_strrchr(prm->arguments[1], st[*i]))
			prm->arguments[1] = (x[1]++, ft_chrjoin(prm->arguments[1], st[*i]));
		*i += 1;
	}
	return (x[1]);
}

void	get_option_args(char *buffer, int *i, t_prompt *swap)
{
	if ((buffer[*i] == '-') && (buffer[*i + 1] != ' ') && !swap->arguments[2])
		swap->n_options = option_gen(swap, buffer, i);
	else
		swap->arguments = \
			str_strjoin_freeall(swap->arguments, read_word(buffer, i));
}
