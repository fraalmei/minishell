/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:04:38 by vpujalte          #+#    #+#             */
/*   Updated: 2023/09/07 15:00:22 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(int error, char *argument)
{
	if (error >= 0)
	{
		// ft_putstr_fd("pipex: ", STDERR);
		// ft_putstr_fd(strerror(error), STDERR);
		// ft_putstr_fd(": ", STDERR);
		// ft_putstr_fd(argument, STDERR);
		// ft_putstr_fd("\n", STDERR);
		exit(errno);
	}
	else
	{
		if (error == -1)
		{
			ft_putstr_fd("pipex: Command not found: ", STDERR);
			ft_putstr_fd(argument, STDERR);
			ft_putstr_fd("\n", STDERR);
		}
		if (error == -2)
			ft_putstr_fd("pipex: Invalid number of arguments\n", STDERR);
		if (error == -3)
			ft_putstr_fd("pipex: Error at dup2\n", STDERR);
		exit(0);
	}
}
