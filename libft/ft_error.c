/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:04:38 by vpujalte          #+#    #+#             */
/*   Updated: 2023/10/26 14:05:15 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../include/mshellmsg.h"

int	ft_error(int error, char *str, char *msg_error)
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
	else if (error == 5)
		ft_printf_fd(STDERR, "syntax error near `%s'\n", str);
	else if (error == 6)
		ft_printf_fd(STDERR, "illegal option -- -\n");
	else if (error == 10)
		ft_printf_fd(STDERR, "Comillas abiertas\n");
	else if (error == 11)
		ft_printf_fd(STDERR, "$%s: ambiguous redirect\n", str);
	else if (error == 12)
		ft_printf_fd(STDERR, "No se aceptan opciones\n");
	else if (error == 13)
		ft_printf_fd(STDERR, "%s: too many strs\n", str);
	else if (error == 127)
		ft_printf_fd(STDERR, "minishell: cd: %s No such file or directory\n",
			str);
	if (str)
		free (str);
	return (error);
}

/*
{
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(strerror(error), STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putstr_fd(str, STDERR);
	ft_putstr_fd("\n", STDERR);
	exit(errno);
}
*/
int	ft_q_error(int error, char *msg_error)
{
	if (error == 10)
		ft_printf_fd(STDERR, Q_ERR_01);
	else if (error == 11)
		ft_printf_fd(STDERR, Q_ERR_02);
	else if (error == 12)
		ft_printf_fd(STDERR, Q_ERR_03);
	else if (error == 13)
		ft_printf_fd(STDERR, Q_ERR_04);
	else if (error == 127)
		ft_printf_fd(STDERR, Q_ERR_05);
}

int	ft_t_error(int error, char *msg_error)
{
	if (error == 5)
		ft_printf_fd(STDERR, T_ERR_01);
	else if (error == 6)
		ft_printf_fd(STDERR, T_ERR_02);
	else if (error == 10)
		ft_printf_fd(STDERR, T_ERR_03, str);
	else if (error == 11)
		ft_printf_fd(STDERR, T_ERR_04);
	else if (error == 12)
		ft_printf_fd(STDERR, T_ERR_05);
	else if (error == 13)
		ft_printf_fd(STDERR, T_ERR_06);
	else if (error == 127)
		ft_printf_fd(STDERR, T_ERR_07);
}