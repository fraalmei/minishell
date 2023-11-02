/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:40:06 by fraalmei          #+#    #+#             */
/*   Updated: 2023/11/02 08:50:54 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <dirent.h>

static int	change_dir_env(t_env_var **env, char *dir)
{
	char	*str;

	if (get_value(*env, "PWD"))
		str = ft_strjoin_allfree(ft_strdup("OLDPWD="), \
			ft_strdup(get_value(*env, "PWD")));
	else
	{
		str = ft_strjoin_allfree(ft_strdup("OLDPWD="), \
			get_wd_char());
	}
	set_value(env, str);
	free (str);
	str = ft_strjoin_allfree(ft_strdup("PWD="), dir);
	if (get_env(*env, "PWD"))
		set_value(env, str);
	free (str);
	return (0);
}

static char	*cd_check_oldpwd(void)
{
	char	*home;

	home = get_value(g_ms->envirorment->frst, "OLDPWD");
	if (!home)
	{
		ft_printf_fd (2, "cd: OLDPWD not set\n");
		g_ms->signals->status_code = 1;
		return (NULL);
	}
	ft_printf("%s\n", home);
	return (home);
}

static char	*cd_check_home(void)
{
	char	*home;

	home = get_value(g_ms->envirorment->frst, "HOME");
	if (!home)
	{
		ft_printf_fd (2, "cd: HOME not set\n");
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
	else if (ft_strcmp(arg, "-") == 0)
		arg = cd_check_oldpwd();
	if (!arg)
		return (1);
	else if (ft_strcmp(arg, "") == 0)
		return (0);
	dir = opendir(arg);
	if (!dir)
		return (ft_printf_fd(STDERR, \
		"minishell: cd: %s No such file or directory\n", arg), 1);
	closedir(dir);
	i = chdir(arg);
	arg = get_wd_char();
	change_dir_env(&g_ms->envirorment->frst, arg);
	return (i);
}
