/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:24:31 by mgrau             #+#    #+#             */
/*   Updated: 2022/06/14 08:34:11 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include <sys/wait.h>

/*
** launch_several_process **
	variables
		i		int type
			this variable controls number of process
	while exist process do (i check)

	pipe instruction was used to create pipe streams
	take the element sh_pid with fokr order
		if sh_pid is 0 we are in child process
			in this moment close fd[0], the read end of the pipe
		in other case we are in father
			need to control signals ft_signal_main
			close necesary pipes
			close FD and reasign elements
//			ft_signal_main();?
	rinse and repeat
	wait for execution to finish
*/

void	launch_several_process(t_lst *node, int i)
{
	int		new_fd_list[2];
	int		old_fd_list [2];
	t_lst	*tmp;

	tmp = node;
	while (i > 0)
	{
		if (i != 1)
			pipe(new_fd_list);
		g_ms->sh_pid = fork();
		if (g_ms->sh_pid == 0)
		{
			if (i != 1)
				close(new_fd_list[0]);
			if (node->exe_state == SUCCESS)
				execute_child(tmp, new_fd_list, old_fd_list);
			else
				exit(0);
		}
		else
			handle_pipes(tmp, new_fd_list, old_fd_list);
		tmp->node_pid = g_ms->sh_pid;
		tmp = tmp->next;
		i--;
	}
}

/*
	** handle_pipes **
	change old_pipe to fd list
	if last close new_pip[0] all new pipe is closed
	copy our pipe, note that even if we copy new_pipe[1] 
	is always closed at this point. therefore old pipe[1] is always closed
*/

void	handle_pipes(t_lst *node, int new_pip[2], int old_pip[2])
{
	if (node->el_nbr != 1)
		close(old_pip[0]);
	if (node->el_nbr != g_ms->prcs_n)
	{
		close(new_pip[1]);
		copy_pipe(new_pip, old_pip);
	}
	close_all_fds(node);
}

void	copy_pipe(int *pipe_in, int *pipe_out)
{
	pipe_out[0] = pipe_in[0];
	pipe_out[1] = pipe_in[1];
}

/*
	** execute_child **
	/handle_defs(node->str_args);	//just as in single proccess we handle 
	definitions adding them to env list and erasing them from our cmd list
	if here doc stdin set to it
	if its NOT the first element
		if fd_in is 0, we assing the read end of our old list else it closes old_fd[0]
	if eits NOT the last
		if fd_in is 1, we assing the write end of our new_list else it closes new_fd[1]
*/

void	execute_child(t_lst *node, int new_fd_list[2], int old_fd_list[2])
{
	open_heredoc(node);
	if (node->el_nbr != 1)
		assing_fd(&node->file_in, old_fd_list[0], FD_IN);
	if (node->el_nbr != g_ms->prcs_n)
		assing_fd(&node->file_out, new_fd_list[1], FD_OUT);
	if (node->str_args[0])
	{
		if (is_builtin(node->str_args[0]))
		{
			dup_to_stdin_stdout(node->file_in, node->file_out);
			exec_builtin(node->str_args, 0);
		}
		else
			call_execve(node);
	}
}

void	wait_childs(void)
{
	int		state;
	t_lst	*tmp;

	tmp = g_ms->instr;
	while (tmp)
	{
		state = 0;
		g_ms->sh_pid = tmp->node_pid;
		ft_set_signal();
		waitpid(tmp->node_pid, &state, 0);
		if (tmp->next == NULL)
			ft_get_errstatus(state);
		tmp = tmp->next;
	}
}
