/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:54:33 by fraalmei          #+#    #+#             */
/*   Updated: 2023/08/04 16:13:30 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/// @brief copy and generate a struct for the envirorment
/// @param env the father envirorment
/// @return the envirorent struct
t_env	*read_env(char **env)
{
	t_env		*copy;
	t_env_var	*swap;
	int			i;

	i = 0;
	if (!env)
		return (NULL);
	copy = (t_env *)ft_calloc(sizeof(copy), 2);
	if (!copy)
		return (NULL);
	copy->env = copy_env(env);
	printf("%s\n", env[i]);
	swap = new_struct_env(env[i++]);
	copy->frst = swap;
	while (env[i])
	{
		printf("%s\n", env[i]);
		swap->next = new_struct_env(env[i++]);
		swap = swap->next;
	}
	return (copy);
}
