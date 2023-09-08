/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:45:48 by cagonzal          #+#    #+#             */
/*   Updated: 2023/09/08 11:25:01 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <executer.h>

void	launch_from_child(t_prompt *prompt)
{
	g_ms->sh_pid = fork();
	if (g_ms->sh_pid == 0)
		call_execve(prompt);
	else
	{
		close_all_fds(prompt);
		prompt->node_pid = g_ms->sh_pid;
		wait_childs();
	}
}

void	launch_single_process(t_prompt *prompt)
{
	if (prompt->input_redirect)
		ft_inredir(prompt);
	if (prompt->output_redirect)
		ft_outredir(prompt);
	if (prompt->command)
	{
		if (is_builtin(prompt->command))
			launch_from_father(prompt);
		else
			launch_from_child(prompt);
	}
}

void	start_executer(void)
{
	ft_heredoc();
	g_ms->n_prompts = ft_lstpromptsize(g_ms->prompt);
	if (g_ms->n_prompts == 1)
		launch_single_process(g_ms->prompt);
	// else
	// {
	// 	launch_pipe_process(g_ms->prompt, g_ms->n_prompts);
	// 	wait_childs();
	// }
}
