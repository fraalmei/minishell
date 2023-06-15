/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:54:33 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/06 14:54:29 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**copy_env(char **env)
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
}

static t_env_var	*copy_env_list(char **env)
{
	t_env_var	*first;
	int			i;

	i = 0;
	first = new_struct_env(ft_split(env[i++], '='));
	while (env[i])
	{
		if (ft_str_frst_cmp(env[i], "_=") != 0)
			set_value(first, ft_split(env[i], '='));
		i++;
	}
	return (first);
}

void	set_value_frst(t_env_var **list, t_env_var *node)
{
	node->next = *list;
	*list = node;
}

void	sort_in_list(t_env_var **list, t_env_var *node)
{
	t_env_var	*copy_list;

	if (!*list || ft_strcmp(node->name, (*list)->name) < 0)
		set_value_frst(list, node);
	else
	{
		copy_list = *list;
		while (copy_list->next && \
				ft_strcmp(node->name, copy_list->next->name) >= 0)
			copy_list = copy_list->next;
		node->next = copy_list->next;
		copy_list->next = node;
	}
}

static t_env_var	*copy_env_sort_list(char **env)
{
	t_env_var	*first;
	int			i;

	i = 0;
	first = NULL;
	while (env[i])
	{
		if (ft_str_frst_cmp(env[i], "_=") != 0)
			sort_in_list (&first, new_struct_env(ft_split(env[i], '=')));
		i++;
	}
	return (first);
}

t_env	*read_env(char **env)
{
	t_env		*copy;
	int			i;

	if (!env)
		return (NULL);
	copy = (t_env *)ft_calloc(sizeof(*copy), 1);
	if (!copy)
		return (NULL);
	copy->env = copy_env(env);
	copy->frst_en = copy_env_list(env);
	copy->frst_ex = copy_env_sort_list(env);
	i = -1;
	while (env[++i])
		if (ft_str_frst_cmp(env[i], "_=") == 0)
			copy->dir = new_struct_env(ft_split(env[i], '='));
	return (copy);
}
