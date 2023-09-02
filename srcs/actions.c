/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:18:16 by fraalmei          #+#    #+#             */
/*   Updated: 2023/09/02 13:28:42 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	add_args(t_prompt *prompt, char *str)
{
	prompt->arguments = str_strjoin_freeall(prompt->arguments, ft_strdup(str));
	prompt->n_arguments = 1;
	return (0);
}

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
	else if (prompt->command && !prompt->arguments)
		add_args (prompt, ".");
	return (0);
}
