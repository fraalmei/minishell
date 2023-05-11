/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:38:03 by fraalmei          #+#    #+#             */
/*   Updated: 2022/08/10 16:34:35 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// copy "src" and concatenate to "dst"
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			j;
	char			*d;
	const char		*s;

	j = 0;
	d = dst;
	s = src;
	if (dstsize < 1)
		return (ft_strlen(s));
	while (s[j] && j < dstsize - 1)
	{
		d[j] = s[j];
		j++;
	}
	d[j] = '\0';
	return (ft_strlen(s));
}
