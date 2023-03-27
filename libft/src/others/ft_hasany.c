/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hasany.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:15:56 by jre-gonz          #+#    #+#             */
/*   Updated: 2023/02/17 14:39:37 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/// @brief		Analizes a string looking for char/s returning 1 if
///				any of those exists an 0 if not.
/// @param str	String to analize
/// @param c	Char/s to find
/// @return		Returns 1 or 0
int	ft_hasany(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
		if (c == str[i++])
			return (1);
	return (0);
}
