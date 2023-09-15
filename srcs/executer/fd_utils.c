/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:24:32 by cagonzal          #+#    #+#             */
/*   Updated: 2023/09/15 11:23:35 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <executer.h>

void	assing_fd(int *prompt_fd, int new_fd, int fd)
{
	if (*prompt_fd == fd)
		(printf("Entra en prompt_fd == fd\n"), *prompt_fd = new_fd);
	else
		(printf("Entra en assign_fd else\n"), close(new_fd));
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

void	close_all_fds(t_prompt *prompt)
{
	if (prompt->infile != 0)
	{
		close(prompt->infile);
		prompt->infile = 0;
	}
	if (prompt->outfile != 1)
	{
		close(prompt->outfile);
		prompt->outfile = 1;
	}
}

void	add_flag(size_t *pos, int *flg, int t)
{
		(*flg) = t;
		(*pos)++;
}
