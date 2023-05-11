/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:32:48 by mgrau             #+#    #+#             */
/*   Updated: 2023/04/20 12:47:03 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	start_executer(void)
{
	int		i;
	t_lst	*node;

	g_ms->state = EXECUTING;
	i = g_ms->prcs_n;
	node = g_ms->instr;
	if (i == 1)
		launch_single_process(node);
	else
	{
		launch_several_process(node, i);
		wait_childs();
	}
	g_ms->state = READING;
}

/*
**launch_single_process**
	handle defs checks if the arguments are
	definitions, adds them and removes them from our cmd list in this node
		open heredoc checks if there is a heredoc name and opens it
		if there is an argument
		is it a built in?
		if it is will launch from father
		if not we must fork just like in several process route
*/

void	launch_single_process(t_lst *node)
{
	if (node->exe_state == SUCCESS)
	{
		open_heredoc(node);
		if (node->str_cmd)
		{
			if (is_builtin(node->str_args[0]))
				launch_from_father(node);
			else
				launch_from_fork(node);
		}
	}
}

/*
**launch_from_father**
	Since we are lauching from father we create
	a back up for the original stdin and stdout
	We asing the new stdin stdout if any chages apply
	1 means father, we exec our built in
	We close and restore original stdin stdout if needed
*/

void	launch_from_father(t_lst *node)
{
	int		stdin_fd;
	int		stdout_fd;

	stdin_fd = dup(0);
	stdout_fd = dup(1);
	dup_to_stdin_stdout(node->file_in, node->file_out);
	exec_builtin(node->str_args, 1);
	dup_to_stdin_stdout(stdin_fd, stdout_fd);
}

/*
**launch_from_fork**
	we fork
	if we are in child we go to execution
	if we are in father
	we close our fds
	we wait for the child to finish execution
	set state as reading again
*/

void	launch_from_fork(t_lst *node)
{
	g_ms->sh_pid = fork();
	if (g_ms->sh_pid == 0)
		call_execve(node);
	else
	{
		close_all_fds(node);
		node->node_pid = g_ms->sh_pid;
		wait_childs();
		g_ms->state = READING;
	}
}

/*
** call_execve **
	we set our stdin and stdout appropiately
	get our cmd path for execution
	clone our env list for the execution
*/

void	call_execve(t_lst *node)
{
	char	*path;
	char	**env;
	int		err;

	dup_to_stdin_stdout(node->file_in, node->file_out);
	path = get_pathname(node->str_args[0]);
	env = str_ptr_dup(g_ms->sh_env);
	if (execve(path, node->str_args, env) == -1)
	{
		err = errno;
		ft_msg(node->str_args[0], 2);
		ft_msg(Q_ERR_03, 2);
		close_all_fds(node);
		ft_execve_free();
		exit(err);
	}
}
