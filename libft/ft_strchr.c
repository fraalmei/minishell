/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:54:18 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/22 00:29:36 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// find the first coincidence of 'c' in "s"
	// returning a ponter to this position
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

	// find the first coincidence of 'c' in "s"
	// returning a the position
int	ft_str_frst_chr(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

	// find the first coincidence of 'c' in "s"
	// returning a the position if exist
	// or -1 if dont find coincidence
int	ft_str_chr(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (!str[i])
		return (-1);
	else
		return (i);
}

	// count the amount of 'c' of 'n' chars in "str"
int	ft_strnchr(char *str, char c, size_t n)
{
	size_t	i;

	i = 0;
	while (str[i] != c && str[i] && i < n)
		i++;
	if (!str[i])
		return (-1);
	else
		return (i);
}

	// find and return the positions of the coincidences of 'c' in 's'
int	*ft_str_all_chr(char *str, char c)
{
	int		i;
	int		count;
	int		*positions;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] == c)
			count++;
	positions = ft_calloc(sizeof(int), count + 1);
	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] == c)
			positions[count++] = i;
	return (positions);
}
