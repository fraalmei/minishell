/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:40:06 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/20 11:25:18 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <dirent.h>

static int	change_dir_env(t_env_var **env, char *dir)
{
	char	*str;

	str = ft_strjoin_allfree(ft_strdup("OLDPWD="), \
		ft_strdup(get_value(*env, "PWD")));
	set_value(env, str);
	free (str);
	str = ft_strjoin_allfree(ft_strdup("PWD="), dir);
	set_value(env, str);
	free (str);
	return (0);
}

	// funcion cd
	// si existe el directorio se mueve a el
	// necesaria libreria dirent.h
	// genera leaks
int	cd(t_prompt *prompt)
{
	DIR		*dir;
	int		i;

	dir = opendir(prompt->arguments[1]);
	if (!dir)
	{
		return (printf ("no such file or directory: %s\n", \
			prompt->arguments[1]), ERROR);
	}
	closedir(dir);
	i = chdir(prompt->arguments[1]);
	change_dir_env(&g_ms->envirorment->frst, get_wd_char());
	return (i);
}
