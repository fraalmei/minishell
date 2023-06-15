/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:18:16 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/15 12:56:07 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// check the buffer command
	// * if (sizeof(g_ms->envirorment->dir) == sizeof(t_env_var))
	// 	the if condition dont work if only check the existence of "dir"
	// * if (g_ms->envirorment->dir)
int	actions(t_prompt *prompt)
{
	if (ft_strcmp(prompt->command, "exit") == 0)
		exit_shell();
	else if (ft_strcmp(prompt->command, "pwd") == 0)
		get_wd();
	else if (ft_strcmp(prompt->command, "env") == 0)
	{
		print_env(g_ms->envirorment->frst_en);
		if (g_ms->envirorment->dir != NULL)
			print_env(g_ms->envirorment->dir);
	}
	else if (ft_strcmp(prompt->command, "export") == 0)
		export(prompt);
	else if (ft_strcmp(prompt->command, "cd") == 0)
		cd(prompt);
	else if (ft_strcmp(prompt->command, "unset") == 0)
	{
		unset(&g_ms->envirorment->frst_en, prompt->arguments);
		unset(&g_ms->envirorment->frst_ex, prompt->arguments);
	}
	else if (ft_strcmp(prompt->command, "echo") == 0)
		echo(g_ms->prompt);
	return (0);
}
/*
** is_builtin **
	we check if our arg is a builtin
*/

int	is_builtin(char *arg)
{
	if (ft_strcmp(arg, "pwd"))
		return (1);
	else if (ft_strcmp(arg, "cd"))
		return (1);
	else if (ft_strcmp(arg, "echo")
		return (1);
	else if (ft_strcmp(arg, "env"))
		return (1);
	else if (ft_strcmp(arg, "export"))
		return (1);
	else if (ft_strcmp(arg, "unset"))
		return (1);
	else if (ft_strcmp(arg, "exit"))
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
	if (ft_strcmp(arg[0], "pwd"))
		ft_pwd();
	else if (ft_strcmp(arg[0], "cd"))
		ft_cd(arg[1]);
	else if (ft_strcmp(arg[0], "echo")
		ft_echo(arg);
	else if (ft_strcmp(arg[0], "env"))
		ft_env();
	else if (ft_strcmp(arg[0], "export"))
		ft_export(arg);
	else if (ft_strcmp(arg[0], "unset"))
		ft_unset(arg);
	else if (ft_strcmp(arg[0], "exit"))
		ft_exit(arg, type);
	if (type == 0)
		exit (0);
}
