/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:18:16 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/15 12:47:35 by fraalmei         ###   ########.fr       */
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
