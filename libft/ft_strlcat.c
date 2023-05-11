/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:19:01 by fraalmei          #+#    #+#             */
/*   Updated: 2022/08/10 16:33:33 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// copy and concatenate string with the same input parameters
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	int				k;
	char			*d;
	const char		*s;

	i = dstsize;
	d = dst;
	s = src;
	while (i-- != 0 && *d != '\0')
		d++;
	k = d - dst;
	i = dstsize - k;
	if (i == 0)
		return (k + ft_strlen(src));
	while (*s != '\0')
	{
		if (i != 1)
		{
			*d++ = *s;
			i--;
		}
		s++;
	}
	*d = '\0';
	return (k + (s - src));
}
