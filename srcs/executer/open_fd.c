/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:43:02 by cagonzal          #+#    #+#             */
/*   Updated: 2023/11/16 10:38:32 by fraalmei         ###   ########.fr       */
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
		prompt->infile = openfile(prompt, prompt->input_redirect[i], INFILE);
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
			prompt->outfile = openfile(prompt, prompt->output_redirect[i] \
					, OUTFILE);
		}
		else
		{
			prompt->output_redirect[i] = ft_strtrim_frst_onefree(\
				prompt->output_redirect[i], ">>");
			prompt->outfile = openfile(prompt, prompt->output_redirect[i] \
					, APPFILE);
		}
	}
}

int	openfile(t_prompt *prompt, char	*filename, int mode)
{
	int	fd;

	fd = -1;
	if (mode == INFILE)
	{
		if (access(filename, R_OK) != 0)
			prompt->b_success = ft_file_err(filename);
		fd = open(filename, O_RDONLY);
	}
	else if (mode == OUTFILE)
	{
		if (access(filename, R_OK) == 0)
			prompt->b_success = (unlink(filename), 1);
		fd = open(filename, O_RDWR | O_CREAT, S_IRWXU);
	}
	else if (mode == APPFILE)
	{
		if (access(filename, W_OK) == 0)
			fd = open(filename, O_RDWR | O_APPEND);
		else
			fd = open(filename, O_RDWR | O_CREAT, S_IRWXU);
	}
	if (fd == -1 && mode != INFILE)
		prompt->b_success = ft_file_err(filename);
	return (fd);
}
