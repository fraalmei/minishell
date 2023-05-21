/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:49:52 by fraalmei          #+#    #+#             */
/*   Updated: 2023/05/21 16:04:12 by fraalmei         ###   ########.fr       */
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
			ft_printf("%s", var->name);
			ft_printf("=");
			ft_printf("%s\n", var->value);
			var = var->next;
		}
	}
}
