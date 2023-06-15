/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:39:55 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/06 13:10:43 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	remove_node(t_env_var **prev, t_env_var *node)
{
	if ((*prev) == node)
	{
		(*prev) = node->next;
		node->next = NULL;
		free_env_var(node);
	}
	else if (node->next)
	{
		(*prev)->next = node->next;
		node->next = NULL;
		free_env_var(node);
	}
	else
	{
		(*prev)->next = NULL;
		node->next = NULL;
		free_env_var(node);
	}
}

	// busca el nombre en env y export y los elimina
int	unset(t_env_var **env, char *name)
{
	t_env_var	*prev;
	t_env_var	*node;

	if (get_name((*env), name))
	{
		node = *env;
		if (ft_strcmp((*env)->name, name) == 0)
		{
			remove_node(env, node);
			return (0);
		}
		while (node)
		{
			if (ft_strcmp(node->name, name) == 0)
			{
				return (remove_node(&prev, node), 0);
			}
			prev = node;
			node = prev->next;
		}
	}
	return (0);
}
