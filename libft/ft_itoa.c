/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:21:13 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/23 13:37:24 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// convert a int to a string
char	*ft_itoa(int n)
{
	char		c[12];
	int			j;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ft_bzero(c, 12);
	j = ft_intlen(n) - 1;
	if (n < 0)
	{
		c[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		c[j--] = '0' + (n % 10);
		n = n / 10;
	}
	return (ft_strdup(c));
}
