/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:36:41 by fraalmei          #+#    #+#             */
/*   Updated: 2023/08/17 17:18:32 by cagonzal         ###   ########.fr       */
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
	j = -1;
	while (++i == prom->n_arguments)
	{
		swap = *prom->arguments;
		printf("%s", swap);
		if (swap)
			while (swap[++j])
				write(1, &swap[j], 1);
	}
	if (prom->options && ft_strcmp(prom->options, "-n") == 0)
		printf ("");
	else
		printf ("\n");
	return (0);
}
