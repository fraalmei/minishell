/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:19:05 by cagonzal          #+#    #+#             */
/*   Updated: 2023/08/28 09:09:53 by fraalmei         ###   ########.fr       */
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
void launch_from_father(t_prompt *prompt)
{
	int		stdin_fd;
	int		stdout_fd;

	stdin_fd = dup(0);
	stdout_fd = dup(1);
	dup_to_stdin_stdout(prompt->infile, prompt->infile);
	actions(prompt);
	dup_to_stdin_stdout(stdin_fd, stdout_fd);
}

static char	*get_pathname(char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	path = env[i] + 5;
	while (path && ft_strchr(path, ':'))
	{
		dir = ft_strndup(path, ft_strichr(path, ':'));
		bin = ft_strjoin(dir, "/");
		bin = ft_strjoin(bin, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_strichr(path, ':') + 1;
	}
	return (cmd);
}

void	call_execve(t_prompt *prompt)
{
	char	*path;
	char	**env;
	int		err;

	env = g_ms->envirorment->env;
	path = get_pathname(prompt->command[0], env);
	if (execve(path, prompt->arguments, env) == -1)
	{
		err = errno;
		free_prompt(prompt);
		exit(UNKNOWN_COMMAND);
	}
}
