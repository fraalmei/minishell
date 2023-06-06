/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:36:41 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/06 11:32:06 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
	value = get_value(g_mishell->envirorment->frst, name);
	if (value)
	{
		while (*value)
			write (1, value++, 1);
		write (1, " ", 1);
	}
	free (name);
	return (i);
}

int	echo(t_prompt *prom)
{
	char	*swap;
	int		i;

	i = -1;
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
	printf ("\n");
	return (0);
}
