/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:36:50 by fraalmei          #+#    #+#             */
/*   Updated: 2023/08/01 16:54:21 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// find the first coincidence of 'c' in "s"
	// returning a ponter to this position
int	ft_frst_chrcmp(const char *s, int c)
{
	if (s[0] == (unsigned char)c)
		return (1);
	return (0);
}

int	ft_lst_chrcmp(const char *s, int c)
{
	while (*s)
		s++;
	s--;
	if (*s == (unsigned char)c)
		return (1);
	return (0);
}

	// return the position of the position of a character of trim
int	ft_chrcmp_str(const char *str, char *trim)
{
	int		i;
	int		l;

	i = 0;
	while (str[i])
	{
		l = 0;
		while (trim[l])
		{
			if (str[i] == trim[l])
				return (i);
			l++;
		}
		i++;
	}
	return (-1);
}

	// return the position when not alphanumeric char
int	ft_chrcmp_alphanum(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		printf("%c - %i\n", str[i], ft_isalnum(str[i]));
		if (ft_isalnum(str[i]) == 0)
		{
			return (i);
		}
		i++;
	}
	return (i);
}
