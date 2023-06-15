/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:17:32 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/14 15:43:19 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// count how many chars have "c"
size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

	// count how many pointers have "string"
size_t	ft_strlen_array(const void **string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}
