/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:23:41 by fraalmei          #+#    #+#             */
/*   Updated: 2023/09/08 18:01:10 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	set_value(t_env_var *env, char *var)
{
	t_env_var	*swap;
	char		**str;

	if (!env)
		return ;
	swap = env;
	while (swap->next)
	{
		str = ft_split(var, '=');
		if (ft_strcmp(swap->name, str[0]) == 0)
		{
			if (swap->value != NULL)
				free (swap->value);
			if (ft_str_frst_chr(var, '=') >= 0)
			{
				swap->equal = '=';
				if (!str[1])
					swap->value = NULL;
				else
					swap->value = str[1];
			}
			free (str[0]);
			free (str);
			return ;
		}
		free_str (str);
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

int	incr_shll_lvl(t_env_var *env)
{
	int		i;
	char	*swap;
	char	*lvl;

	i = ft_atoi(get_value(env, "SHLVL"));
	i++;
	lvl = ft_itoa(i);
	swap = ft_strjoin(ft_strdup("SHLVL="), lvl);
	free (lvl);
	set_value(env, swap);
	return (0);
}
