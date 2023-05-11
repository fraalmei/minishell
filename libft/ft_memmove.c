/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:00:25 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/23 13:36:18 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// se copia "n" caracteres de "src" a "dst"
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char	*s;
	unsigned char		*ld;
	unsigned const char	*ls;

	if (src == NULL && dst == NULL)
		return (NULL);
	d = dst;
	s = src;
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		ld = d + (len - 1);
		ls = s + (len - 1);
		while (len--)
			*ld-- = *ls--;
	}
	return (dst);
}
