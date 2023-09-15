/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:20:08 by cagonzal          #+#    #+#             */
/*   Updated: 2023/09/15 10:49:11 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <executer.h>

void	launch_pipe_process(t_prompt *prompt)
{
	int			pipefd[2];
	int			auxfd[2];
	t_prompt	*tmp;

	tmp = prompt;
	while (tmp)
	{
		if (!tmp->sep1)
			pipe(pipefd);
		g_ms->sh_pid = fork();
		if (g_ms->sh_pid == 0)
		{
			if (!tmp->sep1)
				close(pipefd[0]);
			if (prompt->b_success == SUCCESS)
				prepare_exec(tmp, pipefd, auxfd);
			else
				exit(0);
		}
		else
			handle_pipes(tmp, pipefd, auxfd);
		tmp->node_pid = g_ms->sh_pid;
		tmp = tmp->next;
	}
}

void	handle_pipes(t_prompt *prompt, int pipefd[2], int auxfd[2])
{
	if (prompt->sep1)
		close(auxfd[0]);
	if (!prompt->sep1)
	{
		close(pipefd[1]);
		copy_pipe(pipefd, auxfd);
	}
	close_all_fds(prompt);
}

void	copy_pipe(int *in, int *out)
{
	out[0] = in[0];
	out[1] = in[1];
}

void	prepare_exec(t_prompt *prompt, int pipefd[2], int auxfd[2])
{
	if (prompt->input_redirect)
		(ft_inredir(prompt), assing_fd(&prompt->infile, auxfd[0], INFILE));
	if (prompt->output_redirect)
		(ft_outredir(prompt), assing_fd(&prompt->outfile, pipefd[1], OUTFILE));
	if (prompt->command)
	{
		if (is_builtin(prompt->command))
		{
			dup_to_stdin_stdout(prompt->infile, prompt->outfile);
			actions(prompt);
		}
		else
			call_execve(prompt);
	}
}

void	wait_childs(void)
{
	int			state;
	t_prompt	*tmp;

	tmp = g_ms->prompt;
	while (tmp)
	{
		state = 0;
		g_ms->sh_pid = tmp->node_pid;
		// signals_do();
		waitpid(tmp->node_pid, &state, 0);
		tmp = tmp->next;
	}
}
/*
	if (prompt->b_success == TRUE)
		prepare_exec(tmp, fd, auxfd, prompt);
	else
		exit(0);
*/
