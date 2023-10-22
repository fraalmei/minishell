/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:36:41 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/22 04:46:58 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// echo con opción -n
int	echo(t_prompt *prom)
{
	char	**swap;
	int		i;
	int		t;

	i = 1;
	t = 0;
	swap = prom->arguments;
	if (prom->n_options == 1 && ft_strcmp(prom->arguments[i], "-n") == 0)
		i++;
	while (swap[i])
	{
		if (t++ > 0 && swap[i])
			printf(" ");
		if (ft_strcmp(swap[i], "~") != 0)
			printf("%s", swap[i]);
		/* else
			printf(); */
		i++;
	}
	if (prom->n_options > 0 && ft_strcmp(prom->arguments[1], "-n") == 0)
		return (0);
	else
		printf ("\n");
	return (0);
}
