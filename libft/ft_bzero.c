/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:06:44 by fraalmei          #+#    #+#             */
/*   Updated: 2022/08/10 12:51:40 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// bzero call to memset to fill "i" positions of "c" with '\0'
void	ft_bzero(void *c, size_t i)
{
	ft_memset(c, '\0', i);
}
