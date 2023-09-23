/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:57:24 by fraalmei          #+#    #+#             */
/*   Updated: 2023/09/22 16:22:34 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/// @brief return the value of a global variable when a $ is finded
/// @param buffer the buffer of the line
/// @param i the position in the buffer
/// @return the value of the variable if exist
char	*return_wild(char *buffer, int *i)
{
	int		x;
	char	*name;
	char	*value;

	x = *i;
	if (buffer[x + 1] != ' ' && buffer[x + 1] && ft_isalnum(buffer[x + 1]))
		x = ft_chrcmp_alphanum(&buffer[x + 1]);
	else if (buffer[x + 1] == '{' && buffer[x + 1])
	{
		x = ft_str_chr(&buffer[x], '}');
		if (x == -1)
			return (NULL);
		name = ft_substr(&buffer[*i], 2, x - 2);
	}
	else
		return ("$");
	name = ft_substr(buffer, *i + 1, x);
	value = get_value(g_ms->envirorment->frst, name);
	free (name);
	*i += x;
	return (value);
}
