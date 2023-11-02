/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:49:52 by fraalmei          #+#    #+#             */
/*   Updated: 2023/11/02 08:50:26 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// imprime las variables de entorno en el orden de copia
	// los creados van aleatorios
	// opciones con i para imprimir
	// imprimir con env directamente
void	print_env(t_env_var	*env)
{
	while (env)
	{
		if (env->equal)
		{
			ft_printf("%s", env->name);
			ft_printf("=");
			if (env->value)
				ft_printf("%s\n", env->value);
			else
				ft_printf("\n");
		}
		env = env->next;
	}
}

int	ft_env(void)
{
	print_env(g_ms->envirorment->frst);
	if (g_ms->envirorment->dir != NULL)
		print_env(g_ms->envirorment->dir);
	g_ms->signals->status_code = 0;
	return (0);
}
