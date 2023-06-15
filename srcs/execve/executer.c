/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:36:23 by cagonzal          #+#    #+#             */
/*   Updated: 2023/06/15 12:59:22 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <fcntl.h>
#include <stddef.h>

void	start_executer(void)
{
	int		i;
	t_list	*node;

	i = 0;
	node = g_ms->prompt;
	while (g_ms->prompt->next)
	{
		node = g_ms->prompt->next;
		i++;
	}
	if (i == 1)
		single_process(node);
	else
	{
		several_process(node);
		wait_childs();
	}
}

void	single_process(t_lst *node)
{
	if (node->command)
	{
		if (is_builtin(node->command))
			exec_from_parent(node);
		else
			exec_from_fork(node);
	}

}

void	exec_from_father(t_lst *node)
{
	int		stdin_fd;
	int		stdout_fd;

	stdin_fd = dup(0);
	stdout_fd = dup(1);
	dup_to_stdin_stdout(node->file_in, node->file_out);
	exec_builtin(node->str_args, 1);
	dup_to_stdin_stdout(stdin_fd, stdout_fd);
}

void	exec_from_fork(t_lst *node)
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
