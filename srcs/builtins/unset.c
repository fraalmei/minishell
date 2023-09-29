/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:39:55 by fraalmei          #+#    #+#             */
/*   Updated: 2023/09/29 10:44:51 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	free_node(t_env_var *env)
{
	env->name = NULL;
	free(env->name);
	if (env->value)
	{
		env->value = NULL;
		free (env->value);
	}
	env = NULL;
	free (env);
	return (0);
}

int	remove_node(t_env_var **env, char *var)
{
	t_env_var	*swap1;
	t_env_var	*swap2;

	if (!env)
		return (0);
	swap1 = *env;
	if (ft_strcmp(swap1->name, var) == 0)
	{
		*env = swap1->next;
		return (free_node(swap1));
	}
	swap2 = swap1;
	swap1 = swap1->next;
	while (swap1)
	{
		if (ft_strcmp(swap1->name, var) == 0)
		{
			swap2->next = swap1->next;
			return (free_node(swap1));
		}
		swap2 = swap1;
		swap1 = swap1->next;
	}
	return (0);
}

	// busca el nombre en env y export y los elimina
int	unset(t_env_var **env, char **name)
{
	int			i;

	i = -1;
	while (name[++i])
	{
		remove_node(env, name[i]);
	}
	return (0);
}
