/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:19:05 by cagonzal          #+#    #+#             */
<<<<<<< Updated upstream
<<<<<<< HEAD
/*   Updated: 2023/10/19 17:06:51 by cagonzal         ###   ########.fr       */
=======
/*   Updated: 2023/10/19 11:01:32 by fraalmei         ###   ########.fr       */
>>>>>>> 1fac7cafe3d338624d98bbc29b6b56f473520e1b
=======
/*   Updated: 2023/10/19 13:59:19 by fraalmei         ###   ########.fr       */
>>>>>>> Stashed changes
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
	int		err;

	signals_in_process();
	dup_to_stdin_stdout(prompt->infile, prompt->outfile);
	env_to_strstr(g_ms->envirorment);
	path = get_pathname(prompt->command, g_ms->envirorment->env);
	if (execve(path, prompt->arguments, NULL) == -1)
	{
		err = errno;
		ft_error(-1, prompt->command);
<<<<<<< Updated upstream
		close_all_fds(prompt);
		free_prompt(prompt);
		exit(err);
=======
		init_signals();
		// free_prompt(prompt);
		exit(g_ms->signals->status_code);
>>>>>>> Stashed changes
	}
}
