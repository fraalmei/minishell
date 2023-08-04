/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:57:24 by fraalmei          #+#    #+#             */
/*   Updated: 2023/08/02 16:39:54 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// imprime los valores de las variables globales cuando se incluye $
	// $? no implementado
char	*return_wild(char *str, int *i)
{
	int		x;
	char	*name;
	char	*value;

	x = *i;
	x = ft_chrcmp_alphanum(&str[x + 1]);
	name = ft_substr(str, *i + 1, x);
	value = get_value(g_ms->envirorment->frst, name);
	free (name);
	*i += x;
	return (value);
}
