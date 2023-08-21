/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:45:48 by cagonzal          #+#    #+#             */
/*   Updated: 2023/08/21 16:15:01 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <executer.h>

// void	launch_from_child(t_prompt prompt)
// {
// 	g_ms->sh_pid = fork();
// 	if (g_ms->sh_pid == 0)
// 		call_execve(&prompt);
// 	else
// 	{
// 		close_all_fds(&prompt);
// 		// wait_childs();
// 	}
// }

void	launch_single_process(t_prompt *prompt)
{

	if (prompt->command)
	{
		if (is_builtin(prompt->command))
			launch_from_father(prompt);
		// else
		// 	launch_from_child(prompt);
	}
}

void	start_executer(void)
{
	g_ms->n_prompts = ft_lstpromptsize(g_ms->prompt);
	if (g_ms->n_prompts == 1)
		launch_single_process(g_ms->prompt);
	// else
	// {
	// 	launch_mult_process(g_ms->prompt);
	// 	wait_childs();
	// }
}
