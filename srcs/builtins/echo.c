/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:36:41 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/19 16:57:32 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// echo con opción -n
int	echo(t_prompt *prom)
{
	char	*swap;
	int		i;

	i = -1;
	swap = NULL;
	if (prom->arguments)
		write(1, &swap[i], 1);
	if (prom->options && ft_strcmp(prom->options, "-n") == 0)
		printf ("");
	else
		printf ("\n");
	return (0);
}
