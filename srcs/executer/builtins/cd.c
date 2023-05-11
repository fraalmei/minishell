/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:17:50 by cagonzal          #+#    #+#             */
/*   Updated: 2023/04/26 14:19:32 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	cd_error(char *path)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(" No such file or directory\n", 2);
}

void	ft_cd(char *str)
{
	char	*s;

	if (str == NULL)
		s = ft_strdup(getenv("HOME"));
	else
		s = ft_strdup(str);
	if (chdir(s) == -1)
		cd_error(s);
}

int	envfind(char *name)
{
	int		x;
	char	*tmp;

	x = -1;
	tmp = ft_strjoin(name, "=");
	while (g_ms->sh_env[++x])
		if (!ft_strncmp(g_ms->sh_env[x], tmp, ft_strlen(tmp)))
			return (free(tmp), x);
	free(tmp);
	return (-1);
}
