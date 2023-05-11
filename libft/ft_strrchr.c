/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:57:42 by fraalmei          #+#    #+#             */
/*   Updated: 2023/04/20 08:42:57 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// find the last coincidence of 'c' in "s"
	// and return a pointer to that position
char	*ft_strrchr(const char *s, int c)
{
	char	*l;

	l = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			l = ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (l);
}

	// find the last coincidence of 'c' in "s"
	// and return the position
int	ft_str_lst_chr(const char *s, int c)
{
	int		i;
	int		l;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			l = i;
		i++;
	}
	return (l);
}
