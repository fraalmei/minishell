/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:12:05 by fraalmei          #+#    #+#             */
/*   Updated: 2023/05/23 12:01:46 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char *argv[])
{
	int		file[4096];
	int		i;
	char	*line;

	i = -1;
	if (argc == 1)
		return (0);
	while (++i < argc - 1)
		file[i] = open(argv[i + 1], O_RDONLY);
	line = ft_strdup(" ");
	while (line)
	{
		i = -1;
		while (++i < argc)
		{
			if (file[i])
			{
				free (line);
				line = get_next_line(file[i]);
				ft_printf ("%i	%s", i, line);
			}
		}
	}
	free (line);
	i = 0;
	while (++i < argc)
		close(file[i]);
	return (0);
}

	//system ("leaks a.out");
