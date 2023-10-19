/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_trim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:42:05 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/09 11:32:00 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// count how many pointers have "string"
int	ft_str_strlen(char **string)
{
	int	i;

	i = 0;
	while (string && string[i])
		i++;
	return (i);
}

	// count the number of characcters until thesecond char is finded
int	ft_scndchrlen(const char *s, char c)
{
	int		i;
	int		n;

	i = -1;
	n = 0;
	while (n < 2 && s[++i])
	{
		if (s[i] == c)
			n++;
	}
	if (s[i])
		return (i);
	else
		return (-1);
}

/// @brief join a string to a string array
/// @param s1 
/// @param s2 
/// @return 
char	**str_strjoin_freeall(char **s1, char *s2)
{
	char	**str;
	int		str_len;
	int		i;

	if (!s1)
		s1 = (char **)ft_calloc(sizeof(char *), 1);
	if (!s1)
		return (NULL);
	str_len = ft_str_strlen(s1);
	i = -1;
	str = (char **)ft_calloc(sizeof(char *), str_len + 2);
	while (s1[++i])
		str[i] = s1[i];
	free (s1);
	str[i] = s2;
	return (str);
}
