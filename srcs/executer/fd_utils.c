/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:24:32 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/27 10:14:31 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <executer.h>

void	assing_fd(int *prompt_fd, int new_fd, int fd)
{
	if (*prompt_fd == fd)
		*prompt_fd = new_fd;
	else
		close(new_fd);
}

void	dup_to_stdin_stdout(int fd_in, int fd_out)
{
	if (fd_in != 0)
	{
		if (dup2(fd_in, 0) == -1)
			(ft_t_error(5, NULL), exit(2));
		close(fd_in);
	}
	if (fd_out != 1)
	{
		if (dup2(fd_out, 1) == -1)
			(ft_t_error(5, NULL), exit(2));
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
