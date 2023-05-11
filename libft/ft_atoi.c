/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:40:48 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/23 13:36:32 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// convert a char string to a int
	// this function only works correctly if the number its a int
int	ft_atoi(const char *str)
{
	int	i;
	int	k;
	int	l;

	i = 0;
	l = 1;
	k = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			l = -1;
	while (str[i] >= '0' && str[i] <= '9')
		k = (str[i++] - '0') + (k * 10);
	return (k * l);
}
