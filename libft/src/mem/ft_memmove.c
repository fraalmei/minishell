/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:30:11 by cagonzal          #+#    #+#             */
/*   Updated: 2023/02/17 14:38:25 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	if (d == NULL && s == NULL)
		return (0);
	if (d > s)
		while (len--)
			d[len] = s[len];
	else if (d < s)
		ft_memcpy(dst, src, len);
	return (dst);
}
