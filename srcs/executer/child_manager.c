/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:20:08 by cagonzal          #+#    #+#             */
/*   Updated: 2023/09/28 15:54:23 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <executer.h>

void	launch_pipe_process(t_prompt *prompt, int i)
{
	int			pipefd[2];
	int			oldpipefd[2];
	t_prompt	*tmp;

	tmp = prompt;
	while (i > 0)
	{
		if (i != 1)
			pipe(pipefd);
		g_ms->sh_pid = fork();
		if (g_ms->sh_pid == 0)
		{
			if (i != 1)
				close(pipefd[0]);
			if (tmp->b_success == SUCCESS)
				prepare_exec(tmp, pipefd, oldpipefd);
			else
				exit(0);
		}
		else
			(handle_pipes(tmp, pipefd, oldpipefd), close_all_fds(tmp));
		tmp->node_pid = g_ms->sh_pid;
		tmp = tmp->next;
		i--;
	}
	wait_childs();
}

void	handle_pipes(t_prompt *prompt, int new_pip[2], int old_pip[2])
{
	if (prompt->pos_p != 1)
		close(old_pip[0]);
	if (prompt->pos_p != g_ms->n_prompts)
	{
		close(new_pip[1]);
		copy_pipe(new_pip, old_pip);
	}
	close_all_fds(prompt);
}

void	copy_pipe(int *pipe_in, int *pipe_out)
{
	pipe_out[0] = pipe_in[0];
	pipe_out[1] = pipe_in[1];
}


void	prepare_exec(t_prompt *prompt, int pipefd[2], int oldpipefd[2])
{
	if (prompt->pos_p != 1)
		assing_fd(&prompt->infile, oldpipefd[0], INFILE);
	if (prompt->pos_p != g_ms->n_prompts)
		assing_fd(&prompt->outfile, pipefd[1], OUTFILE);
	if (prompt->command)
	{
		if (is_builtin(prompt->command))
		{
			dup_to_stdin_stdout(prompt->infile, prompt->outfile);
			actions(prompt, 0);
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
		signals_in_prompt();
		waitpid(tmp->node_pid, &state, 0);
		tmp = tmp->next;
	}
}


// int	*copy_pipe(int pipe_in[2])
// {
// 	int	*pipe_out;

// 	pipe_out = malloc(sizeof(int) * 2);
// 	pipe_out[0] = pipe_in[0];
// 	pipe_out[1] = pipe_in[1];
// 	return (pipe_out);
// }

	// close(new_pip[1]);
	// if (prompt->pos_p != 1)
	// {
	// 	close((old_pip)[0]);
	// 	free(old_pip);
	// }
	// if (prompt->pos_p != g_ms->n_prompts)
	// 	close(new_pip[0]);
	// else
	// 	old_pip = copy_pipe(new_pip);



	// int		pipefd[2];
	// int		*oldpipefd;

	// oldpipefd = NULL;
	// while (i > 0)
	// {
	// 	pipe(pipefd);
	// 	g_ms->sh_pid = fork();
	// 	if (g_ms->sh_pid == 0)
	// 	{
	// 		close(pipefd[0]);
	// 		if (prompt->b_success == SUCCESS)
	// 			prepare_exec(prompt, pipefd, oldpipefd);
	// 		else
	// 			exit(0);
	// 	}
	// 	else
	// 	{
	// 		handle_pipes(prompt, pipefd, oldpipefd);
	// 		close_all_fds(prompt);
	// 	}
	// 	prompt = prompt->next;
	// 	i--;
	// }
