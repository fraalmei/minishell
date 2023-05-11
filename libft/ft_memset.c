/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:24:44 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/23 13:38:01 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// memset fill "len" slots of "dest" with characters "c"
void	*ft_memset(void *dest, int c, size_t len)
{
	size_t			j;
	unsigned char	*ptr;

	j = -1;
	ptr = dest;
	while (++j < len)
		ptr[j] = c;
	return (dest);
}
