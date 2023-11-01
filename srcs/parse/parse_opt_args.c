/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opt_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:57:09 by fraalmei          #+#    #+#             */
/*   Updated: 2023/11/01 17:56:35 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_start_prom(char *buffer, t_prompt *prom)
{
	if (prom == NULL && is_pipe(buffer) > 0)
		return (1);
	return (0);
}

int	check_opt_builtins(t_prompt *swap)
{
	if (ft_strcmp(swap->command, "cd") == 0 || \
			ft_strcmp(swap->command, "env") == 0 || \
			ft_strcmp(swap->command, "exit") == 0 || \
			ft_strcmp(swap->command, "export") == 0 || \
			ft_strcmp(swap->command, "pwd") == 0 || \
			ft_strcmp(swap->command, "unset") == 0)
		return (print_error(12, NULL, 12), 1);
	return (0);
}

int	option_gen(t_prompt *prm, char *buffer, int *i)
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
	while (buffer[*i] && is_redirecction(&buffer[*i]) == 0 && buffer[*i] != ' ')
	{
		if (!ft_strrchr(prm->arguments[1], buffer[*i]))
			prm->arguments[1] = (x[1]++, ft_chrjoin(prm->arguments[1], \
				buffer[*i]));
		i[0]++;
	}
	return (x[1]);
}

static int	check_opt_echo(char *buffer, int i, t_prompt *swap)
{
	int		r;

	r = 0;
	if (ft_strcmp(swap->command, "echo") == 0 && ((!swap->arguments[1] && \
		!swap->arguments[2]) || (ft_strcmp(swap->arguments[1], "-n") == 0 && \
		!swap->arguments[2])))
	{
		if (ft_strncmp(&buffer[i], "--", 2) == 0)
			r = 0;
		else if (buffer[i] == '-')
		{
			i++;
			while (buffer[i] && ft_isalpha(buffer[i]))
			{
				if (buffer[i] == 'n')
					i++;
				else
					return (0);
			}
			r = 1;
		}
	}
	return (r);
}

void	get_option_args(char *buffer, int *i, t_prompt *swap)
{
	if (check_opt_echo(buffer, *i, swap))
		swap->n_options = option_gen(swap, buffer, i);
	else if (ft_strcmp(swap->command, "echo")
		&& ft_strcmp(swap->command, "cd")
		&& (buffer[*i] == '-') && (buffer[*i + 1] != ' ')
		&& !swap->arguments[2])
	{
		if (check_opt_builtins(swap))
			return ;
		swap->n_options = option_gen(swap, buffer, i);
	}
	else
	{
		swap->arguments = \
			str_strjoin_freeall(swap->arguments, read_word(buffer, i));
	}
}
