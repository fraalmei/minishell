/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:19:05 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/02 15:38:22 by cagonzal         ###   ########.fr       */
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
	dup_to_stdin_stdout(prompt->infile, prompt->outfile);
	actions(prompt, 1);
	dup_to_stdin_stdout(stdin_fd, stdout_fd);
}

void	call_execve(t_prompt *prompt)
{
	char	*path;
	char	**env;

	signals_in_process();
	dup_to_stdin_stdout(prompt->infile, prompt->outfile);
	env = env_to_strstr(g_ms->envirorment);
	path = get_pathname(prompt->command, env);
	if (execve(path, prompt->arguments, NULL) == -1)
	{
		g_ms->signals->status_code = UNKNOWN_COMMAND;
		ft_error(-1, prompt->command);
		free_prompt(prompt);
		exit(g_ms->signals->status_code);
	}
}
