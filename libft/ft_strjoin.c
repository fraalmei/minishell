/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:21:21 by fraalmei          #+#    #+#             */
/*   Updated: 2023/04/21 13:11:17 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// allocate space for a new string
	// and join two string in it
char	*ft_strjoin(char const *s1, char const *s2)
{
	void	*s;

	if (!s1)
		s1 = (char *)ft_calloc(1, sizeof(char));
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	ft_strlcat(s, s1, ft_strlen(s1) + 1);
	ft_strlcat(s, s2, ft_strlen(s2) + ft_strlen(s1) + 1);
	return ((char *) s);
}

	// same than before except free allocate memory of the first parameter
char	*ft_strjoin_onefree(char *s1, char const *s2)
{
	void	*s;

	if (!s1)
		s1 = (char *)ft_calloc(1, sizeof(char));
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	ft_strlcat(s, s1, ft_strlen(s1) + 1);
	ft_strlcat(s, s2, ft_strlen(s2) + ft_strlen(s1) + 1);
	return (free(s1), (char *) s);
}
