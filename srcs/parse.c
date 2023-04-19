/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:29:45 by fraalmei          #+#    #+#             */
/*   Updated: 2023/04/19 16:36:08 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	print_deep_split(char ***s)
{
	char	**swap;
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		ft_printf("--------------------------------\n");
		swap = s[i];
		j = 0;
		while (swap[j])
			ft_printf("%s\n", swap[j++]);
		i++;
	}
	return (0);
}

	// function to split the buffer
	// to separate the function and the arguments
	// first split the buffer in pipes
	// second split the pipes in the rest of the elements
char	***deep_split(const char *buffer)
{
	char	***process;
	char	**swap;
	int		i;

	swap = ft_split(buffer, 124);
	if (!swap)
		return (0);
	i = 0;
	while (swap[i])
		i++;
	process = (char ***)malloc(sizeof(char **) * (i));
	if (!process)
		return (0);
	while (i--)
	{
		process[i] = ft_split(swap[i], ' ');
		free (swap[i]);
	}
	free (swap);
	print_deep_split(process);
	return (process);
}
