/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:39:55 by fraalmei          #+#    #+#             */
/*   Updated: 2023/09/11 12:26:03 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	remove_node(t_env_var **prev, t_env_var *node)
{
	if ((*prev) == node)
		(*prev) = node->next;
	else if (node->next)
		(*prev)->next = node->next;
	else
		(*prev)->next = NULL;
	node->next = NULL;
	free_env_var(node);
}

	// busca el nombre en env y export y los elimina
int	unset(t_env_var **env, char **name)
{
	t_env_var	*prev;
	t_env_var	*node;
	int			i;

	i = -1;
	while (name[++i])
	{
		if (get_name((*env), name[i]))
		{
			node = *env;
			if (ft_strcmp((*env)->name, name[i]) == 0)
			{
				remove_node(env, node);
				return (0);
			}
			while (node)
			{
				if (ft_strcmp(node->name, name[i]) == 0)
				{
					return (remove_node(&prev, node), 0);
				}
				prev = node;
				node = prev->next;
			}
		}
	}
	return (0);
}
