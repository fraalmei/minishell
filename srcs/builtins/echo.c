/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:36:41 by fraalmei          #+#    #+#             */
/*   Updated: 2023/09/07 10:45:57 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// echo con opción -n
int	echo(t_prompt *prom)
{
	char	**swap;
	int		i;

	i = 1;
	swap = prom->arguments;
	if (prom->n_options > 0)
		swap++;
	swap++;
	while (i < prom->n_arguments)
	{
		if (*swap)
			printf("%s", *swap);
		swap++;
		i++;
		if (i < prom->n_arguments)
			printf(" ");
	}
	if (prom->n_options > 0 && ft_strcmp(prom->arguments[1], "n") == 0)
		return (0);
	else
		printf ("\n");
	return (0);
}
