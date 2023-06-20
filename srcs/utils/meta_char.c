/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:57:24 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/20 17:38:43 by fraalmei         ###   ########.fr       */
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

	x = ft_chrcmp_str(&str[*i], "\"\t\n\v\f\r <>&|");
	if (x == -1)
		x = ft_strlen(str);
	else
		x -= 1;
	name = ft_substr(str, *i + 1, x);
	value = get_value(g_ms->envirorment->frst_en, name);
	free (name);
	*i += x;
	return (value);
}

