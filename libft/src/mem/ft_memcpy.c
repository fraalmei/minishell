/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:01:31 by cagonzal          #+#    #+#             */
/*   Updated: 2023/02/17 14:38:25 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dst, const void *src, unsigned int n)
{
	unsigned char		*d;
	unsigned const char	*s;

	d = dst;
	s = src;
	if (d == NULL && s == NULL)
		return (0);
	while (n--)
		*d++ = *s++;
	return (dst);
}
