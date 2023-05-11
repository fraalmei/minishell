/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:39:35 by mgrau             #+#    #+#             */
/*   Updated: 2023/04/20 12:27:04 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*
** is_builtin **
	we check if our arg is a builtin
*/

int	is_builtin(char *arg)
{
	if (precise_cmp(arg, "pwd", 3))
		return (1);
	else if (precise_cmp(arg, "cd", 2))
		return (1);
	else if (precise_cmp(arg, "echo", 4))
		return (1);
	else if (precise_cmp(arg, "env", 3))
		return (1);
	else if (precise_cmp(arg, "export", 6))
		return (1);
	else if (precise_cmp(arg, "unset", 5))
		return (1);
	else if (precise_cmp(arg, "exit", 4))
		return (1);
	else
		return (0);
}

/*
** exec_builtin **
	we execute our builtin and exit if child
*/

void	exec_builtin(char **arg, int type)
{
	(void)**arg;
	if (precise_cmp(arg[0], "pwd", 3))
		ft_pwd();
	else if (precise_cmp(arg[0], "cd", 2))
		ft_cd(arg[1]);
	else if (precise_cmp(arg[0], "echo", 4))
		ft_echo(arg);
	else if (precise_cmp(arg[0], "env", 3))
		ft_env();
	// else if (precise_cmp(arg[0], "export", 6))
	// 	ft_export(arg);
	// else if (precise_cmp(arg[0], "unset", 5))
	// 	ft_unset(arg);
	else if (precise_cmp(arg[0], "exit", 4))
		ft_exit(arg, type);
	if (type == 0)
		exit (0);
}

/*
** precise_cmp **
a strncmp that takes the lenght into account
*/

int	precise_cmp(char *s1, char *s2, size_t size)
{
	if (ft_strlen(s1) == size && ft_strlen(s2) \
	== size && !ft_strncmp(s1, s2, size))
		return (1);
	return (0);
}
