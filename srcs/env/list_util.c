/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:08:35 by fraalmei          #+#    #+#             */
/*   Updated: 2023/09/23 13:54:13 by fraalmei         ###   ########.fr       */
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

static char	*env_to_str(t_env_var *frst)
{
	char	*env;
	char	*swap;

	swap = ft_chrjoin(frst->name, frst->equal);
	env = ft_strjoin_onefree(swap, frst->value);
	return (env);
}

char	**env_to_strstr(t_env_var *frst)
{
	char	**env;

	env = NULL;
	while (frst->next)
	{
		env = str_strjoin_freeall(env, env_to_str(frst));
		frst = frst->next;
	}
	env = str_strjoin_freeall(env, env_to_str(frst));
	return (env);
}

static t_env_var	*struct_env(char *name, char eq, char *value)
{
	t_env_var	*env;

	env = (t_env_var *)ft_calloc(sizeof(*env), 2);
	if (!env)
		return (NULL);
	env->name = name;
	env->equal = eq;
	env->value = value;
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
