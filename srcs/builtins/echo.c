/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:36:41 by fraalmei          #+#    #+#             */
/*   Updated: 2023/08/28 11:15:02 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// echo con opción -n
int	echo(t_prompt *prom)
{
	char	*swap;
	int		i;
	int		j;

	i = -1;
	while (++i <= prom->n_arguments)
	{
		j = -1;
		swap = prom->arguments[i];
		if (swap)
		{
			if (i > 0)
				write(1, " ", 1);
			while (swap[++j])
				write(1, &swap[j], 1);
		}
	}
	if (prom->command[1] && ft_strcmp(prom->command[1], "-n") == 0)
		printf ("");
	else
		printf ("\n");
	return (0);
}
