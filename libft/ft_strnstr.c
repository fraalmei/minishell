/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:33:41 by fraalmei          #+#    #+#             */
/*   Updated: 2023/07/31 14:45:58 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// find the first coincidence of neddle
	// in haystack and return a pointer to it in n chars
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

	// find the first coincidence of neddle
	// in haystack and return the first position to it in n chars
int	ft_strnstr_f(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(needle);
	if (i == 0 || ft_strcmp(haystack, needle) == 0 || n == 0)
		return (0);
	j = 0;
	while (haystack[j] != '\0' && j < n)
	{
		k = 0;
		while (haystack[j + k] != '\0' && needle[k] != '\0'
			&& haystack[j + k] == needle[k] && j + k < n)
			k++;
		if (k == i)
			return (j);
		j++;
	}
	return (0);
}

	// find the first coincidence of neddle
	// in haystack and return the last position to it in n chars
int	ft_strnstr_l(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(needle);
	if (i == 0 || ft_strcmp(haystack, needle) == 0 || n == 0)
		return (0);
	j = 0;
	while (haystack[j] != '\0' && j < n)
	{
		k = 0;
		while (haystack[j + k] != '\0' && needle[k] != '\0'
			&& haystack[j + k] == needle[k] && j + k < n)
		{
			k++;
			j++;
		}
		if (k == i)
			return (j);
	}
	return (0);
}
