/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:37:33 by cagonzal          #+#    #+#             */
/*   Updated: 2023/02/17 14:38:25 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	n_len;
	char	*s;

	i = 0;
	s = (char *)str;
	n_len = ft_strlen(to_find);
	if (n_len == 0 || str == to_find)
		return (s);
	while (s[i] != '\0' && i < len)
	{
		c = 0;
		while (s[i + c] != '\0' && to_find[c] != '\0'
			&& s[i + c] == to_find[c] && i + c < len)
			c++;
		if (c == n_len)
			return (s + i);
		i++;
	}
	return (0);
}
