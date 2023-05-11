/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:41:06 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/23 13:37:51 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// locate the first coincidence of 'c' in "s" for "n" characters
	// returning a pointer to that position
void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*t;

	t = s;
	while (n--)
		if (*t++ == (char)c)
			return ((char *)--t);
	return (NULL);
}
