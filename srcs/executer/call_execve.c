/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:19:05 by cagonzal          #+#    #+#             */
/*   Updated: 2023/08/28 12:44:39 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <executer.h>

int	ft_strichr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

void	launch_from_father(t_prompt *prompt)
{
	int		stdin_fd;
	int		stdout_fd;

	stdin_fd = dup(0);
	stdout_fd = dup(1);
	dup_to_stdin_stdout(prompt->infile, prompt->infile);
	actions(prompt);
	dup_to_stdin_stdout(stdin_fd, stdout_fd);
}

void	call_execve(t_prompt *prompt)
{
	char	*path;
	int		err;

	// if Set here_doc redir
		// .........
	// else if Set input_redir
		// .........
	// if Set output_redir
		// .........
	if (!prompt->command)
		exit(UNKNOWN_COMMAND);
	path = get_pathname(prompt->command, g_ms->envirorment->env);
	if (execve(path, prompt->arguments, g_ms->envirorment->env) == -1)
	{
		err = errno;
		free_prompt(prompt);
		exit(UNKNOWN_COMMAND);
	}
}
