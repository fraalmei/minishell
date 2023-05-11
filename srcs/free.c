/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:02:58 by fraalmei          #+#    #+#             */
/*   Updated: 2023/05/10 12:21:59 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	free_prompt(t_prompt *prom)
{
	while (prom)
	{
		if ((prom->command))
			free (prom->command);
		if ((prom->arguments))
			free (prom->arguments);
		if ((prom->options))
			free (prom->options);
		free (prom);
		prom = prom->next;
	}
	return (0);
}
