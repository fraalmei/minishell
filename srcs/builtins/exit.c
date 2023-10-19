/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:37:47 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/09 17:28:54 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	exit_shell(t_prompt *prom)
{
	if (prom != NULL && prom->n_arguments > 2)
	{
		print_error(ft_strdup("exit"), 13);
		return (1);
	}
	else if (prom != NULL && prom->n_arguments == 2)
	{
		g_ms->signals->exit_return = ft_atoi(prom->arguments[1]);
		exit (g_ms->signals->exit_return);
	}
	free_global();
	exit (g_ms->signals->exit_return);
}
