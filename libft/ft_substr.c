/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:00:38 by fraalmei          #+#    #+#             */
/*   Updated: 2022/08/10 16:46:53 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// allocate memory and return a string inside of "s"
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;

	if (!s)
		return (NULL);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	c = ft_calloc(sizeof(char), len + 1);
	if (c != NULL)
	{
		if (start > ft_strlen(s))
			return ((char *)c);
		return (ft_memcpy(c, s + start, len));
	}
	return (NULL);
}
