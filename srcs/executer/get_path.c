/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:55:50 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/21 20:50:09 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <executer.h>

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

static unsigned int	ft_strcharcpy(char *dest, char *src, char until,
						unsigned int pos)
{
	unsigned int	i;

	i = 0;
	if ((!dest) || (!src))
		return (0);
	while ((src[pos] != '\0' && src[pos] != until))
		dest[i++] = src[pos++];
	dest[i] = 0;
	return (++pos);
}

static int	create_probable_str(char **dest, char *arg, char *src, int i)
{
	if (dest != NULL)
	{
		*dest = malloc(sizeof(char) * ft_strlen((src + i)) + \
		ft_strlen(arg) + 2);
		i = ft_strcharcpy(*dest, (src + i), ':', 0) + i;
		ft_strcat(*dest, "/");
		ft_strcat(*dest, arg);
	}
	return (i);
}

static char	*get_pathlocation(char **env)
{
	int	i;

	i = 0;
	while (env[i] && (ft_strncmp("PATH=", env[i], 5)))
		i++;
	return (env[i]);
}

char	*get_pathname(char *cmd, char **env)
{
	unsigned int	i;
	char			*dest;
	char			*paths;

	i = 5;
	if ((access(cmd, F_OK)) != -1)
		return (cmd);
	dest = NULL;
	paths = get_pathlocation(env);
	if (paths)
	{
		i = create_probable_str(&dest, cmd, paths, i);
		while ((access(dest, F_OK)) == -1)
		{
			if (i >= strlen(paths) - 5)
			{
				free(dest);
				return (NULL);
			}
			free(dest);
			i = create_probable_str(&dest, cmd, paths, i);
		}
	}
	return (dest);
}
