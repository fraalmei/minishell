/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:08:35 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/23 15:45:22 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*env_to_str(t_env_var *frst)
{
	char	*env;
	char	*swap;

	swap = ft_chrjoin(frst->name, frst->equal);
	env = ft_strjoin_onefree(swap, frst->value);
	return (env);
}

char	**env_to_strstr(t_env *env)
{
	char	**str;

	str = NULL;
	while (env->frst->next)
	{
		str = str_strjoin_freeall(str, env_to_str(env->frst));
		env->frst = env->frst->next;
	}
	str = str_strjoin_freeall(str, env_to_str(env->frst));
	str = str_strjoin_freeall(str, env_to_str(env->dir));
	free_str(env->env);
	env->env = str;
	return (str);
}

static t_env_var	*struct_env(char *name, char eq, char *value)
{
	t_env_var	*env;

	env = (t_env_var *)ft_calloc(sizeof(*env), 2);
	if (!env)
		return (NULL);
	env->name = name;
	env->equal = eq;
	if (eq == '=')
	{
		if (value != NULL)
			env->value = value;
		else
			env->value = ft_strdup("");
	}
	return (env);
}

t_env_var	*new_struct_env(char *var)
{
	t_env_var	*env;
	char		**swap;

	swap = NULL;
	swap = ft_split(var, '=');
	if (ft_str_chr(var, '=') >= 0)
		env = struct_env(swap[0], '=', swap[1]);
	else
		env = struct_env(*swap, 0, NULL);
	free(swap);
	env->next = NULL;
	return (env);
}
