/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:08:35 by fraalmei          #+#    #+#             */
/*   Updated: 2023/08/04 16:13:35 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	list_len(t_env_var *first)
{
	int			i;
	t_env_var	*swap;

	i = 0;
	swap = first;
	while (swap->next)
	{
		swap = swap->next;
		i++;
	}
	return (i);
}

t_env_var	*lst_strct_env(t_env_var *env)
{
	while (env->next)
		env = env->next;
	return (env);
}

t_env_var	*new_struct_env(char *var)
{
	t_env_var	*env;
	char		**swap;

	env = (t_env_var *)ft_calloc(sizeof(*env), 2);
	if (!env)
		return (NULL);
	if (ft_str_chr(var, '=') >= 0)
	{
		swap = ft_split(var, '=');
		env->name = swap[0];
		env->equal = '=';
		env->value = swap[1];
		free(swap);
	}
	else
	{
		env->name = var;
		env->equal = 0;
		env->value = NULL;
	}
	env->next = NULL;
	return (env);
}