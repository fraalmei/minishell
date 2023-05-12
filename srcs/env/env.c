/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:54:33 by fraalmei          #+#    #+#             */
/*   Updated: 2023/05/12 11:20:11 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_env(t_env	*env, int form)
{
	int			i;
	t_env_var	*var;

	if (form == 0)
	{
		i = -1;
		while (env->env[++i])
			ft_printf("%s\n", env->env[i]);
	}
	else
	{
		var = env->frst;
		while (var)
		{
			ft_printf("%s\n", var->var);
			ft_printf("%s\n", var->value);
			var = var->next;
		}
	}
}

t_env_var	*new_struct_env(char **var)
{
	t_env_var	*env;

	if (var[2])
		return (NULL);
	env = (t_env_var *)ft_calloc(sizeof(*env), 1);
	if (!env)
		return (NULL);
	env->var = var[0];
	env->value = var[1];
	env->next = NULL;
	free (var);
	return (env);
}

char	**copy_env(char **env)
{
	char	**copy;
	int		i;

	i = 0;
	while (env[i])
		i++;
	copy = (char **)ft_calloc(sizeof(char **), i);
	if (!copy)
		return (NULL);
	i = -1;
	while (env[++i])
		copy[i] = ft_strdup(env[i]);
	return (copy);
}

t_env	*read_env(char **env)
{
	t_env		*copy;
	t_env_var	*swap;
	int			i;

	i = 0;
	if (!env)
		return (NULL);
	copy = (t_env *)ft_calloc(sizeof(copy), 1);
	if (!copy)
		return (NULL);
	copy->env = copy_env(env);
	swap = new_struct_env(ft_split(env[i++], '='));
	copy->frst = swap;
	while (env[i])
	{
		swap->next = new_struct_env(ft_split(env[i++], '='));
		swap = swap->next;
	}
	return (copy);
}
