/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:43:02 by cagonzal          #+#    #+#             */
/*   Updated: 2023/09/07 14:52:33 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <executer.h>

int	openfile(char *filename, int mode)
{
	if (mode == INFILE)
	{
		if (open (filename, O_RDONLY) < 0)
			ft_error(errno, filename);
		return (open (filename, O_RDONLY));
	}
	else if (mode == OUTFILE)
	{
		if (open (filename, O_CREAT | O_WRONLY | O_TRUNC, 0644) < 0)
			ft_error(errno, filename);
		return (open (filename, O_CREAT | O_WRONLY | O_TRUNC, 0644));
	}
	else if (mode == APPFILE)
	{
		if (open (filename, O_CREAT | O_WRONLY | O_APPEND, 0644) < 0)
			ft_error(errno, filename);
		return (open (filename, O_CREAT | O_WRONLY | O_APPEND, 0644));
	}
	return (0);
}
