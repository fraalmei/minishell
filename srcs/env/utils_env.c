/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:23:41 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/21 17:03:50 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	set_value(t_env_var **env, char *var)
{
	char	**swap;

	if (!env)
		*env = new_struct_env(var);
	else
	{
		swap = ft_split(var, '=');
		if (get_env(*env, swap[0]))
		{
			if (ft_str_chr(var, '=') >= 0)
			{
				remove_node(env, swap[0]);
				lst_strct_env(*env)->next = new_struct_env(var);
			}
		}
		else
			lst_strct_env(*env)->next = new_struct_env(var);
		free_str (swap);
	}
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
	if (!swap->value)
		return ("");
	return (swap->value);
}

int	get_name(t_env_var *env, char *var)
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

t_env_var	*get_env(t_env_var *env, char *var)
{
	t_env_var	*swap;

	if (!env)
		return (NULL);
	swap = env;
	while (ft_strcmp(swap->name, var))
	{
		if (!swap->next)
			return (NULL);
		swap = swap->next;
	}
	return (swap);
}

int	incr_shll_lvl(t_env_var **env)
{
	int		i;
	char	*swap;
	char	*lvl;

	if (get_value(*env, "SHLVL") != NULL)
		i = ft_atoi(get_value(*env, "SHLVL"));
	else
		i = 0;
	i++;
	lvl = ft_itoa(i);
	swap = ft_strjoin_onefree(ft_strdup("SHLVL="), lvl);
	free (lvl);
	set_value(env, swap);
	free (swap);
	return (0);
}
