/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:37:47 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/27 13:53:04 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// system("leaks -q minishell");

int	exit_shell(t_prompt *prompt)
{
	if (!prompt)
		exit(0);
	if (prompt->n_arguments > 2)
		return (print_error(ft_strdup("exit"), 13), 1);
	free_global();
	if (prompt->n_arguments == 2 && ft_is_str_num(prompt->arguments[1]) != 0)
	{
		ft_printf_fd(2, "exit: exit: %s: numeric argument required\n", \
			prompt->arguments[1]);
		exit(255);
	}
	if (prompt->n_arguments == 2)
		exit (ft_atoi(prompt->arguments[1]));
	exit (0);
}
