/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:18:16 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/05 12:09:35 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// check the buffer command
	// * if (sizeof(g_mishell->envirorment->dir) == sizeof(t_env_var))
	// 	the if condition dont work if only check the existence of "dir"
	// * if (g_mishell->envirorment->dir)
int	actions(t_prompt *prompt)
{
	if (ft_strcmp(prompt->command, "exit") == 0)
		exit_shell();
	else if (ft_strcmp(prompt->command, "pwd") == 0)
		get_wd();
	else if (ft_strcmp(prompt->command, "env") == 0)
	{
		print_env(g_mishell->envirorment->frst, 0);
		if (g_mishell->envirorment->dir != NULL)
			print_env(g_mishell->envirorment->dir, 0);
	}
	else if (ft_strcmp(prompt->command, "export") == 0)
		export(prompt);
	else if (ft_strcmp(prompt->command, "cd") == 0)
		cd(prompt);
	else if (ft_strcmp(prompt->command, "unset") == 0)
	{
		unset(&g_mishell->envirorment->frst, prompt->arguments);
		unset(&g_mishell->envirorment->s_frst, prompt->arguments);
	}
	else if (ft_strcmp(prompt->command, "echo") == 0)
		echo(g_mishell->prompt);
	return (0);
}
