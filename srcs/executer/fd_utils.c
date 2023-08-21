/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:24:32 by cagonzal          #+#    #+#             */
/*   Updated: 2023/08/17 16:26:13 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	assing_fd(int *node_fd, int new_fd, int fd)
{
	if (*node_fd == fd)
		*node_fd = new_fd;
	else
		close(new_fd);
}

void	dup_to_stdin_stdout(int fd_in, int fd_out)
{
	if (fd_in != 0)
	{
		if (dup2(fd_in, 0) == -1)
			exit(2);
		close(fd_in);
	}
	if (fd_out != 1)
	{
		if (dup2(fd_out, 1) == -1)
			exit(2);
		close(fd_out);
	}
}

void	close_all_fds(t_lst *node)
{
	if (node->file_in != 0)
	{
		close(node->file_in);
		node->file_in = 0;
	}
	if (node->file_out != 1)
	{
		close(node->file_out);
		node->file_out = 1;
	}
}

void	add_flag(size_t *pos, int *flg, int t)
{
		(*flg) = t;
		(*pos)++;
}
