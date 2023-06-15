/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:09:54 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/13 09:35:24 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// count the words in which the string is going to be divided
static size_t	ft_words(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*s != '\0')
	{
		if (*s == c)
			j = 0;
		else if (j == 0)
			j = (i++, 1);
		s++;
	}
	return (i);
}

	// count the number of character until the char 'c' is finded
static size_t	ft_chrlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

	// release the memory of all allocated memories
static char	**ft_free_malloc(char **s, size_t i)
{
	while (i + 1 >= 1)
		free ((void *)s[i--]);
	free (s);
	return (NULL);
}

	// split a string in multiples strings
char	**ft_split(const char *s, char c)
{
	char	**str;
	size_t	l;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = -1;
	l = ft_words(s, c);
	str = (char **)ft_calloc(sizeof(char *), (l + 1));
	if (!str)
		return (NULL);
	while (++i < l)
	{
		while (*s == c)
			s++;
		j = ft_chrlen(s, c);
		str[i] = ft_substr(s, 0, j);
		if (!str[i])
			return (ft_free_malloc(str, i));
		s = (ft_strchr(s, (int)c));
	}
	str[i] = 0;
	return (str);
}
