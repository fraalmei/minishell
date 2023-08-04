/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:36:41 by fraalmei          #+#    #+#             */
/*   Updated: 2023/08/03 16:56:45 by fraalmei         ###   ########.fr       */
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
	if (swap)
		while (swap[++i])
			write(1, &swap[i], 1);
	/* if (prom->arguments)
		write(1, &swap[i], 1); */
	if (prom->options && ft_strcmp(prom->options, "-n") == 0)
		printf ("");
	else
		printf ("\n");
	return (0);
}
