/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:54:33 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/08 16:16:52 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/// @brief copy and generate a struct for the envirorment
/// @param env the father envirorment
/// @return the envirorent struct
t_env	*read_env(char **env)
{
	t_env		*copy;
	int			i;

	if (!env)
		return (NULL);
	if (!env[0])
		return (ignored_env());
	copy = (t_env *)ft_calloc(sizeof(*copy), 2);
	if (!copy)
		return (NULL);
	copy->frst = copy_env_list(env);
	i = -1;
	while (env[++i])
		if (ft_str_frst_cmp(env[i], "_=") == 0)
			copy->dir = new_struct_env(env[i]);
	incr_shll_lvl(&copy->frst);
	return (copy);
}

/* char	**copy_env(char **env)
{
	char	**copy;
	int		i;

	i = 0;
	while (env[i])
		i++;
	copy = (char **)ft_calloc(sizeof(char **), i + 1);
	if (!copy)
		return (NULL);
	i = -1;
	while (env[++i])
		copy[i] = ft_strdup(env[i]);
	return (copy);
} */

t_env_var	*copy_env_list(char **env)
{
	t_env_var	*first;
	int			i;

	i = 0;
	first = new_struct_env(env[i++]);
	while (env[i])
	{
		if (ft_str_frst_cmp(env[i], "_=") != 0)
			set_value(&first, env[i]);
		i++;
	}
	return (first);
}

void	set_value_frst(t_env_var **list, t_env_var *node)
{
	node->next = *list;
	*list = node;
}
