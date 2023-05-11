/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:14:41 by mgrau             #+#    #+#             */
/*   Updated: 2022/06/14 08:34:35 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*get_pathname(char *arg)
{
	unsigned int	i;
	char			*dest;
	char			*paths;

	i = 5;
	if (access(arg, X_OK) != -1)
		return (ft_strdup(arg));
	dest = NULL;
	paths = get_pathlocation(g_ms->sh_env);
	if (paths)
	{
		i = create_probable_str(&dest, arg, paths, i);
		while ((access(dest, X_OK)) == -1)
		{
			if (i >= strlen(paths) - 5)
			{
				free(dest);
				return (NULL);
			}
			free(dest);
			i = create_probable_str(&dest, arg, paths, i);
		}
	}
	return (dest);
}

char	*get_pathlocation(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && (ft_strncmp("PATH=", envp[i], 5)))
		i++;
	return (envp[i]);
}

int	create_probable_str(char **dest, char *arg, char *src, int i)
{
	if (dest != NULL)
	{
		*dest = malloc(sizeof(char) * \
		ft_strlen((src + i)) + ft_strlen(arg) + 2);
		i = ft_strcharcpy(*dest, (src + i), ':', 0) + i;
		ft_strcat(*dest, "/");
		ft_strcat(*dest, arg);
	}
	return (i);
}
