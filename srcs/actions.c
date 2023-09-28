/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:18:16 by fraalmei          #+#    #+#             */
/*   Updated: 2023/09/28 15:20:57 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// check the buffer command
	// * if (sizeof(g_ms->envirorment->dir) == sizeof(t_env_var))
	// 	the if condition dont work if only check the existence of "dir"
	// * if (g_ms->envirorment->dir)
void	actions(t_prompt *prompt, int type)
{
	if (prompt->command && ft_strcmp(prompt->command, "exit") == 0)
		exit_shell();
	else if (prompt->command && ft_strcmp(prompt->command, "pwd") == 0)
		g_ms->signals->status_code = get_wd();
	else if (prompt->command && ft_strcmp(prompt->command, "env") == 0)
	{
		print_env(g_ms->envirorment->frst);
		if (g_ms->envirorment->dir != NULL)
			print_env(g_ms->envirorment->dir);
		g_ms->signals->status_code = 0;
	}
	else if (prompt->command && ft_strcmp(prompt->command, "export") == 0)
		g_ms->signals->status_code = export(prompt);
	else if (prompt->command && ft_strcmp(prompt->command, "cd") == 0)
		g_ms->signals->status_code = cd(prompt);
	else if (prompt->command && ft_strcmp(prompt->command, "unset") == 0)
		g_ms->signals->status_code = \
			unset(&g_ms->envirorment->frst, prompt->arguments);
	else if (prompt->command && ft_strcmp(prompt->command, "echo") == 0)
		g_ms->signals->status_code = echo(g_ms->prompt);
	if (type == 0)
		exit (0);
}
