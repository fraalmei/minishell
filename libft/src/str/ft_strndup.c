/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:34:31 by cagonzal          #+#    #+#             */
/*   Updated: 2023/02/17 14:38:25 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strndup(const char *str, unsigned int n)
{
	char			*duped;
	unsigned int	i;

	i = 0;
	duped = (char *)ft_calloc(sizeof(char), (n + 1));
	while (i < n)
		duped[i++] = *str++;
	duped[n] = 0;
	return (duped);
}
