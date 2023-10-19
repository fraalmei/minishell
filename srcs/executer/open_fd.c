/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:43:02 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/19 17:15:15 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <executer.h>
#include <dirent.h>

/**
 * @brief Create a directory using execve.
 *
 * This function creates a directory specified by `TMP_PATH`
 * using the `mkdir` command.
 * If the directory already exists, it does nothing.
 *
 * @return 0 on success, or an error code on failure.
 */
int	ft_create_directory(void)
{
	char	*command;
	char	*args[3];
	pid_t	pid;
	DIR		*dir;

	dir = opendir(TMP_PATH);
	if (!dir)
	{
		pid = fork();
		if (pid == 0)
		{
			command = "/bin/mkdir";
			args[0] = command;
			args[1] = TMP_PATH;
			args[2] = NULL;
			execve(command, args, NULL);
		}
		else
			waitpid(pid, NULL, 0);
	}
	else
		closedir(dir);
	return (0);
}

/**
 * @brief Remove a directory using execve.
 *
 * This function removes a directory specified by `TMP_PATH`
 * using the `rm -rf` command.
 * If the directory does not exist, it does nothing.
 *
 * @return 0 on success, or an error code on failure.
 */
int	ft_remove_directory(void)
{
	char	*command;
	char	*args[4];
	pid_t	pid;
	DIR		*dir;

	dir = opendir(TMP_PATH);
	if (dir)
	{
		closedir(dir);
		pid = fork();
		if (pid == 0)
		{
			command = "/bin/rm";
			args[0] = command;
			args[1] = "-rf";
			args[2] = TMP_PATH;
			args[3] = NULL;
			execve(command, args, NULL);
		}
		else
			waitpid(pid, NULL, 0);
	}
	return (0);
}

void	ft_inredir(t_prompt *prompt)
{
	int	i;

	i = -1;
	while (prompt->input_redirect[++i])
		prompt->infile = openfile(prompt->input_redirect[i], INFILE);
}

void	ft_outredir(t_prompt *prompt)
{
	int	i;

	i = -1;
	while (prompt->output_redirect[++i])
	{
		if (prompt->output_redirect[i][1] != '>')
		{
			prompt->output_redirect[i] = ft_strtrim_frst_onefree(\
				prompt->output_redirect[i], ">");
			prompt->outfile = openfile(prompt->output_redirect[i] \
					, OUTFILE);
		}
		else
		{
			prompt->output_redirect[i] = ft_strtrim_frst_onefree(\
				prompt->output_redirect[i], ">>");
			prompt->outfile = openfile(prompt->output_redirect[i] \
					, APPFILE);
		}
	}

}

int	openfile(char	*filename, int mode)
{
	if (mode == INFILE)
	{
		if (open (filename, O_RDONLY) < 0)
			ft_error(errno, filename);
		return (open (filename, O_RDONLY));
	}
	else if (mode == OUTFILE)
	{
		if (open (filename, O_CREAT | O_WRONLY | O_TRUNC, 0644) < 0)
			ft_error(errno, filename);
		return (open (filename, O_CREAT | O_WRONLY | O_TRUNC, 0644));
	}
	else if (mode == APPFILE)
	{
		if (open (filename, O_CREAT | O_WRONLY | O_APPEND, 0644) < 0)
			ft_error(errno, filename);
		return (open (filename, O_CREAT | O_WRONLY | O_APPEND, 0644));
	}
	return (0);
}
