/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:49:52 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/05 12:13:47 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_env(t_env_var	*env, int i)
{
	while (env)
	{
		if (i == 0)
			ft_printf("%s", env->name);
		else if (i == 1)
			ft_printf("declare -x %s", env->name);
		ft_printf("=");
		if (env->value && i == 0)
			ft_printf("%s\n", env->value);
		else if (env->value && i == 1)
			ft_printf("\"%s\"\n", env->value);
		else if (i == 0)
			ft_printf("\n");
		else if (i == 1)
			ft_printf("\"\"\n");
		env = env->next;
	}
}
