/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:45:43 by fraalmei          #+#    #+#             */
/*   Updated: 2022/08/10 13:58:20 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// compare "n" chars of two strings
	// return the diference with the two first diferent chars
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*d;
	const unsigned char		*s;

	if (0 == n || s1 == s2)
		return (0);
	d = s1;
	s = s2;
	while (n--)
		if (*d++ != *s++)
			return (*--d - *--s);
	return (0);
}
