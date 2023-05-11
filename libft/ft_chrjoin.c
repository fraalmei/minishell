/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:51:39 by fraalmei          #+#    #+#             */
/*   Updated: 2022/08/10 13:02:30 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// alternative version of strjoin to join a char 
	// to a string and return a new string freeing the old string
char	*ft_chrjoin(char *s1, char s2)
{
	char	*s;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	s = ft_calloc(sizeof(char), i + 2);
	if (!s || s1 == NULL || s2 == 0)
		return (NULL);
	i = -1;
	while (s1[++i])
		s[i] = s1[i];
	s[i++] = s2;
	s[i] = '\0';
	free(s1);
	return ((char *) s);
}
