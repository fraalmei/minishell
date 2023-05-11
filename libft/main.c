/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:22:41 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/23 13:35:18 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	int		i;
	char	**d;
	char	*s;

	printf ("-------------------------------------------\n");
	s = ft_substr("abcdefghyjklmnñopqrstuvwxyz", 0, 7);
	printf ("ft_substr:		%s\n", s);
	free(s);
	printf ("-------------------------------------------\n");
	s = ft_strjoin("ostia", "puta");
	printf ("ft_strjoin:		%s\n", s);
	free(s);
	printf ("-------------------------------------------\n");
	s = ft_strtrim("1234567890987654321", "0124");
	printf ("ft_strtrim:		%s\n", s);
	free(s);
	printf ("-------------------------------------------\n");
	d = ft_split("supercalifragilisticoespialidoso", 'a');
	return (0);
}

int	main(void)
{
	int		i;
	char	**d;
	char	*s;

	i = 0;
	while (d[i])
	{
		printf ("ft_split:		%s\n", d[i]);
		free (d[i]);
		i++;
	}
	free (d);
	return (0);
}

int	main(void)
{
	int		i;
	char	**d;
	char	*s;

	s = ft_itoa(-576381);
	printf ("ft_itoa:		%s\n", s);
	free (s);
	printf ("-------------------------------------------\n");
	i = atoi("-2147483650");
	printf ("ft_atoi:		%d\n", i);
	i = ft_atoi("-2147483650");
	printf ("ft_atoi:		%d\n", i);
	printf ("-------------------------------------------\n");
	s = ft_strmapi("aaaaaaaaaaaaaaaaaaaaa", ft_toupper);
	printf ("ft_strjoin:		%s\n", s);
	free(s);
	printf ("-------------------------------------------\n");
	system ("leaks a.out");
	return (0);
}
