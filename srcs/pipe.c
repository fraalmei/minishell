/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:28:07 by fraalmei          #+#    #+#             */
/*   Updated: 2023/05/21 10:49:54 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*getpath(char *cmd, char **env)
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
		dir = ft_strndup(path, ft_str_frst_chr(path, ':'));
		bin = ft_strjoin(dir, "/");
		bin = ft_strjoin(bin, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_str_frst_chr(path, ':') + 1;
	}
	return (0);
}
/* 
int	exec(char *cmd, char **env)
{
	char	**args;
	char	*path;
	int		i;

	i = 1;
	args = ft_split(cmd, ' ');
	if (ft_strchr(args[0], '/'))
		path = args[0];
	else
		path = getpath(args[0], env);
	while (args[i])
	{
		if (args[i][0] == 39)
			args[i] = ft_substr(args[i], 1, ft_strlen(args[i]));
		if (args[i][ft_strlen(args[i]) - 1] == 39)
			args[i] = ft_substr(args[i], 0, ft_strlen(args[i]) - 1);
		i++;
	}
	execve(path, args, env);
	ft_printf("Ejecuta las funciones de entorno\n");
	return (0);
} */
