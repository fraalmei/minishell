/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:04:38 by vpujalte          #+#    #+#             */
/*   Updated: 2023/11/16 10:35:18 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../include/minishell.h"
#include "../include/mshellmsg.h"

static int	t_error_2(int error, char *str)
{
	if (error == 5)
		ft_printf_fd(STDERR, "syntax error near `%s'\n", str);
	else if (error == 6)
		ft_printf_fd(STDERR, "illegal option -- -\n");
	else if (error == 10)
		ft_printf_fd(STDERR, "Open quotes\n");
	else if (error == 11)
		ft_printf_fd(STDERR, "$%s: ambiguous redirect\n", str);
	else if (error == 12)
		ft_printf_fd(STDERR, "No options acepted\n");
	else if (error == 13)
		ft_printf_fd(STDERR, "%s: too many strs\n", str);
	else if (error == 127)
		ft_printf_fd(STDERR, "minishell: cd: %s No such file or directory\n",
			str);
	else if (error == 258)
		return (ft_printf_fd(STDERR, T_ERR_258, str));
	return (error);
}

int	ft_error(int error, char *str)
{
	if (error == 0)
		ft_printf_fd(STDERR, "export: `%s': not a valid identifier\n", str);
	else if (error == 1)
		ft_printf_fd(STDERR, ": bad substitution\n");
	else if (error == 7)
		ft_printf_fd(STDERR, "%s not found\n", str);
	else if (error == 2)
		ft_printf_fd(STDERR, "syntax error near unexpected token `%s'\n", str);
	else if (error == 3)
		ft_printf_fd(STDERR, "bad assigment\n");
	else if (error == 4)
		ft_printf_fd(STDERR, "bad option: %s\n", str);
	else if (error == 8)
		ft_printf_fd(STDERR, "found forbiden char `%s'\n", str);
	else
		t_error_2(error, str);
	return (error);
}

int	ft_q_error(int error, char *argument)
{
	if (error == 1)
		return (ft_printf_fd(STDERR, Q_ERR_01));
	else if (error == 2)
		return (ft_printf_fd(STDERR, Q_ERR_02));
	else if (error == 3)
		return (ft_printf_fd(STDERR, Q_ERR_03));
	else if (error == 127)
		return (ft_printf_fd(STDERR, Q_ERR_127, argument));
	return (0);
}

int	ft_t_error(int error, char *argument)
{
	if (error == 1)
		return (ft_printf_fd(STDERR, T_ERR_01));
	else if (error == 2)
		return (ft_printf_fd(STDERR, T_ERR_02));
	else if (error == 3)
		return (ft_printf_fd(STDERR, T_ERR_03));
	else if (error == 4)
		return (ft_printf_fd(STDERR, T_ERR_04));
	else if (error == 5)
		return (ft_printf_fd(STDERR, T_ERR_05));
	else if (error == 6)
		return (ft_printf_fd(STDERR, T_ERR_06));
	else if (error == 7)
		return (ft_printf_fd(STDERR, T_ERR_07, argument));
	else if (error == 8)
		return (ft_printf_fd(STDERR, T_ERR_08));
	else if (error == 9)
		return (ft_printf_fd(STDERR, T_ERR_09, argument));
	else if (error == 258)
		return (ft_printf_fd(STDERR, T_ERR_258));
	return (0);
}

int	ft_file_err(char *file)
{
	ft_putstr_fd(GN_MSG_02, 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	return (ERROR);
}
