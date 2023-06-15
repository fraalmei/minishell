/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:33:41 by fraalmei          #+#    #+#             */
/*   Updated: 2023/05/21 16:33:15 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// find the first coincidence of neddle in haystack, n chars
char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(needle);
	if (i == 0 || haystack == needle)
		return ((char *)haystack);
	j = 0;
	while (haystack[j] != '\0' && j < n)
	{
		k = 0;
		while (haystack[j + k] != '\0' && needle[k] != '\0'
			&& haystack[j + k] == needle[k] && j + k < n)
			k++;
		if (k == i)
			return ((char *)haystack + j);
		j++;
	}
	return (0);
}
