/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:22:28 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/02 13:46:35 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_env	*ignored_env(void)
{
	t_env		*env;
	t_env_var	*first;

	env = (t_env *)ft_calloc(sizeof(*env), 2);
	env->env = NULL;
	first = new_struct_env(ft_strjoin(ft_strdup("PWD="), get_wd_char()));
	env->frst = first;
	set_value(first, "SHLVL=1");
	env->dir = new_struct_env("_=/usr/bin/env");
	return (env);
}
