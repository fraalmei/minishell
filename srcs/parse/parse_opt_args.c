/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opt_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:57:09 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/08 04:06:55 by fraalmei         ###   ########.fr       */
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
		if (st[*i] == '-')
			x[0]++;
		else if (x[0] > 1)
			return (print_error(NULL, 6), -1);
		else if (!ft_strrchr(prm->arguments[1], st[*i]))
			prm->arguments[1] = (x[1]++, ft_chrjoin(prm->arguments[1], st[*i]));
		*i += 1;
	}
	return (x[1]);
}

static int	check_opt_echo(char *buffer, int i, t_prompt *swap)
{
	int		r;

	r = 0;
	if (ft_strcmp(swap->command, "echo") == 0)
	{
		if (ft_strncmp(&buffer[i], "--n", 3) == 0)
			r = 0;
		if (ft_strncmp(&buffer[i], "-n", 2) == 0 && !ft_isalpha(buffer[i + 2]))
			r = 1;
		if (ft_strncmp(&buffer[i], "\"-n\"", 4) == 0 && !ft_isalpha(buffer[i + 2]))
			r = 1;
		if (ft_strncmp(&buffer[i], "'""-n""'", 4) == 0 && !ft_isalpha(buffer[i + 2]))
			r = 1;
	}
	return (r);
}

void	get_option_args(char *buffer, int *i, t_prompt *swap)
{
	if (check_opt_echo(buffer, *i, swap))
		swap->n_options = option_gen(swap, buffer, i);
	if (ft_strcmp(swap->command, "echo") && (buffer[*i] == '-') && \
			(buffer[*i + 1] != ' ') && !swap->arguments[2])
		swap->n_options = option_gen(swap, buffer, i);
	else
		swap->arguments = \
			str_strjoin_freeall(swap->arguments, read_word(buffer, i));
}
