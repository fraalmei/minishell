/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:40:06 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/21 18:45:40 by fraalmei         ###   ########.fr       */
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

/* static char	*cd_check_args(char **args)
{
	int		i;
	//char	*sust;
	//int		l;

	i = 0;
	//sust = NULL;
	while (args[++i])
		return (args[i]);
	return (NULL);
} */

static char	*cd_check_home(void)
{
	char	*home;

	home = get_value(g_ms->envirorment->frst, "HOME");
	if (!home)
	{
		printf ("cd: HOME not set\n");
		g_ms->signals->status_code = 1;
		return (NULL);
	}
	else
		return (home);
}

	// funcion cd
	// si existe el directorio se mueve a el
	// necesaria libreria dirent.h
	// genera leaks
int	cd(t_prompt *prompt)
{
	DIR		*dir;
	char	*arg;
	int		i;

	arg = prompt->arguments[1];
	if (!arg)
		arg = cd_check_home();
	if (!arg || ft_strcmp(arg, "") == 0)
		return (1);
	dir = opendir(arg);
	if (!dir)
		return (ft_error(-3, arg), ERROR);
	closedir(dir);
	i = chdir(arg);
	change_dir_env(&g_ms->envirorment->frst, get_wd_char());
	return (i);
}
