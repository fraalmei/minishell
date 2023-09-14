/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:57:24 by fraalmei          #+#    #+#             */
/*   Updated: 2023/09/14 17:07:27 by fraalmei         ###   ########.fr       */
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
	if (str[x + 1] != ' ' && str[x + 1] && ft_isalnum(str[x + 1]))
		x = ft_chrcmp_alphanum(&str[x + 1]);
	else if (str[x + 1] == '{' && str[x + 1])
	{
		x = ft_str_chr(&str[x], '}');
		if (x == -1)
			return (NULL);
		name = ft_substr(&str[*i], 2, x - 2);
	}
	else
		return ("$");
	name = ft_substr(str, *i + 1, x);
	value = get_value(g_ms->envirorment->frst, name);
	free (name);
	*i += x;
	return (value);
}
