/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:40:06 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/21 16:10:00 by fraalmei         ###   ########.fr       */
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

static char	*cd_check_args(char **args)
{
	int		i;
	char	*sust;
	int		l;

	i = 0;
	sust = NULL;
	while (args[++i])
	{
		if (args[i][0] == '$')
		{
			l = 0;
			sust = return_wild(args[i], &l);
			if (ft_strcmp(sust, ""))
				return (read_word_simple_q_off(&sust), sust);
		}
		else
			return (args[i]);
	}
	return (NULL);
}

static char	*cd_check_home(void)
{
	char	*home;

	home = get_value(g_ms->envirorment->frst, "HOME");
	if (!home)
	{
		printf ("cd: HOME not set\n");
		g_ms->signals->status_code = 1;
	}
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

	arg = cd_check_args(prompt->arguments);
	if (!arg)
		arg = cd_check_home();
	if (!arg)
		return (1);
	dir = opendir(arg);
	if (!dir)
		return (printf ("no such file or directory: %s\n", arg), ERROR);
	closedir(dir);
	i = chdir(arg);
	change_dir_env(&g_ms->envirorment->frst, get_wd_char());
	return (i);
}
