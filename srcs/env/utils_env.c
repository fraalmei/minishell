/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:23:41 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/19 19:04:14 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_env_var	*new_struct_env(char **var)
{
	t_env_var	*env;

	env = (t_env_var *)ft_calloc(sizeof(*env), 1);
	if (!env)
		return (NULL);
	env->name = var[0];
	if (var[1])
		env->value = var[1];
	else
		env->value = NULL;
	env->next = NULL;
	free (var);
	return (env);
}

void	set_value(t_env_var *env, char **var)
{
	t_env_var	*swap;

	if (!env)
		return ;
	swap = env;
	while (swap->next)
	{
		if (ft_strcmp(swap->name, var[0]) == 0)
		{
			if (swap->value != NULL)
				free (swap->value);
			swap->value = var[1];
			free (var[0]);
			free (var);
			return ;
		}
		swap = swap->next;
	}
	swap->next = new_struct_env(var);
}

char	*get_value(t_env_var *env, char	*var)
{
	t_env_var	*swap;

	if (!env)
		return (NULL);
	swap = env;
	while (ft_strcmp(swap->name, var) != 0)
	{
		if (!swap->next)
			return (NULL);
		swap = swap->next;
	}
	return (swap->value);
}

int	get_name(t_env_var *env, char	*var)
{
	t_env_var	*swap;

	if (!env)
		return (0);
	swap = env;
	while (ft_strcmp(swap->name, var))
	{
		if (!swap->next)
			return (0);
		swap = swap->next;
	}
	return (1);
}

t_env_var	*lst_strct_env(t_env_var *env)
{
	while (env->next)
		env = env->next;
	return (env);
}
