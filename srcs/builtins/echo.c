/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:36:41 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/15 12:27:11 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// imprime los valores de las variables globales cuando se incluye $
	// $? no implementado
int	print_wild(char *str)
{
	int		i;
	char	*name;
	char	*value;

	i = ft_strchr_nbr(str, ' ');
	if (i == -1)
		i = ft_strlen(str);
	else
		i -= 1;
	name = ft_substr(str, 0, i);
	value = get_value(g_mishell->envirorment->frst_en, name);
	if (value)
	{
		while (*value)
			write (1, value++, 1);
		if (str[i + 1])
			write (1, " ", 1);
	}
	free (name);
	return (i);
}

	// echo con opción -n
int	echo(t_prompt *prom)
{
	char	*swap;
	int		i;

	i = -1;
	if (prom->arguments)
	{
		swap = prom->arguments;
		while (swap[++i])
		{
			if (swap[i] != '$')
				write(1, &swap[i], 1);
			else
			{
				i++;
				i += print_wild(&swap[i]);
			}
		}
	}
	if (prom->options && ft_strcmp(prom->options, "-n") == 0)
		printf ("");
	else
		printf ("\n");
	return (0);
}
