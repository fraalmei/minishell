/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:20:08 by cagonzal          #+#    #+#             */
/*   Updated: 2023/09/07 14:51:24 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <executer.h>

// void	launch_pipe_process(t_prompt *prompt, int node)
// {
// 	int			fd[2];
// 	int			auxfd[2];
// 	t_prompt	*tmp;

// 	tmp = prompt;
// 	while (node > 0)
// 	{
// 		if (node != 1)
// 			pipe(fd);
// 		g_ms->sh_pid = fork();
// 		if (g_ms->sh_pid == 0)
// 		{
// 			if (node != 1)
// 				close(fd[0]);
// 			if (prompt->b_success == TRUE)
// 				prepare_exec(tmp, fd, auxfd, node);
// 			else
// 				exit(0);
// 		}
// 		else
// 			break ;
// 		tmp->node_pid = g_ms->sh_pid;
// 		tmp = tmp->next;
// 		node--;
// 	}

// }

// void	prepare_exec(t_prompt *prompt, int fd[2], int auxfd[2], int node)
// {
// 	open_heredoc(prompt);
// 	if (node != 1)
// 		assing_fd(&prompt->infile, auxfd[0], INFILE);
// 	if (node != g_ms->n_prompts)
// 		assing_fd(&prompt->outfile, fd[1], OUTFILE);
// 	if (prompt->command)
// 	{
// 		if (is_builtin(prompt->command))
// 		{
// 			dup_to_stdin_stdout(prompt->infile, prompt->outfile);
// 			actions(prompt);
// 		}
// 		else
// 			call_execve(prompt);
// 	}

// }

void	wait_childs(void)
{
	int			state;
	t_prompt	*tmp;

	tmp = g_ms->prompt;
	while (tmp)
	{
		state = 0;
		g_ms->sh_pid = tmp->node_pid;
		waitpid(tmp->node_pid, &state, 0);
		tmp = tmp->next;
	}
}
