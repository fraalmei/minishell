/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:08:29 by cagonzal          #+#    #+#             */
/*   Updated: 2022/07/06 12:00:20 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	initheredoc(int argc, char **argv)
{
	int		fd[2];
	pid_t	pid;

	if (argc < 6)
		ft_error(-2, NULL);
	pipe(fd);
	pid = fork();
	if (pid < 0)
		ft_error(errno, NULL);
	if (pid == 0)
		writeheredoc(fd, argv[2]);
	else
	{
		dup2(fd[0], STDIN);
		close(fd[1]);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}

void	writeheredoc(int fd[2], char *limiter)
{
	char	*line;

	while (1)
	{
		ft_printf("pipex here_doc> ");
		line = get_next_line(STDIN);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			close(fd[1]);
			close(fd[0]);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, fd[STDOUT]);
		free(line);
	}
}
