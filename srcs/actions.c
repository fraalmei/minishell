/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:18:16 by fraalmei          #+#    #+#             */
/*   Updated: 2023/09/04 13:56:27 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// check the buffer command
	// * if (sizeof(g_ms->envirorment->dir) == sizeof(t_env_var))
	// 	the if condition dont work if only check the existence of "dir"
	// * if (g_ms->envirorment->dir)
int	actions(t_prompt *prompt)
{
	if (prompt->command && ft_strcmp(prompt->command, "exit") == 0)
		exit_shell();
	else if (prompt->command && ft_strcmp(prompt->command, "pwd") == 0)
		g_ms->signals->execution_status = get_wd();
	else if (prompt->command && ft_strcmp(prompt->command, "env") == 0)
	{
		print_env(g_ms->envirorment->frst);
		if (g_ms->envirorment->dir != NULL)
			print_env(g_ms->envirorment->dir);
		g_ms->signals->execution_status = 0;
	}
	else if (prompt->command && ft_strcmp(prompt->command, "export") == 0)
		g_ms->signals->execution_status = export(prompt);
	else if (prompt->command && ft_strcmp(prompt->command, "cd") == 0)
		g_ms->signals->execution_status = cd(prompt);
	else if (prompt->command && ft_strcmp(prompt->command, "unset") == 0)
		g_ms->signals->execution_status = \
			unset(&g_ms->envirorment->frst, prompt->arguments);
	else if (prompt->command && ft_strcmp(prompt->command, "echo") == 0)
		g_ms->signals->execution_status = echo(g_ms->prompt);
	return (0);
}
