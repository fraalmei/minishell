/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:20:08 by cagonzal          #+#    #+#             */
/*   Updated: 2023/09/15 12:04:09 by cagonzal         ###   ########.fr       */
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
	printf("Entra en b_success\n");
	if (prompt->input_redirect)
		ft_inredir(prompt);
	if (prompt->output_redirect)
		ft_outredir(prompt);
	if (prompt->sep0[0] == '|')
		assing_fd(&prompt->infile, pipefd[0], INFILE);
	if (prompt->sep1[0] == '|')
		assing_fd(&prompt->outfile, auxfd[1], OUTFILE);
	printf("Continúa en b_success\n");
	if (prompt->command)
	{
		printf("Entra en pregunta si command\n");
		if (is_builtin(prompt->command))
		{
			printf("Entra en builtin\n");
			dup_to_stdin_stdout(prompt->infile, prompt->outfile);
			actions(prompt);
		}
		else
		{
			printf("Entra en call_execve\n");
			call_execve(prompt);
		}
	}
	printf("Sale de prepare exec\n");
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
		signals_do();
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
