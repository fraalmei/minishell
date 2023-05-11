/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:00:14 by fraalmei          #+#    #+#             */
/*   Updated: 2022/08/10 16:36:26 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// apply the function f to every character of "s"
	// to create a new string
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*c;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	c = ft_strdup(s);
	if (!c)
		return (NULL);
	while (c[i])
	{
		c[i] = (*f)(i, c[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}
