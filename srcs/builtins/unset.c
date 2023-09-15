/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:39:55 by fraalmei          #+#    #+#             */
/*   Updated: 2023/09/15 10:40:14 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	remove_node(t_env_var *env, char *var)
{
	t_env_var	*swap1;
	t_env_var	*swap2;

	if (!env)
		return (0);
	swap1 = env;
	while (swap1->next)
	{
		if (ft_strcmp(swap1->name, var) == 0)
		{
			free (swap1->name);
			if (swap1->value)
				free (swap1->value);
			swap2->next = swap1->next;
			free (swap1);
			return (0);
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
		remove_node(*env, name[i]);
	return (0);
}
