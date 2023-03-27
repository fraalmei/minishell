/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:04:38 by vpujalte          #+#    #+#             */
/*   Updated: 2023/02/20 11:27:36 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_error(int error)
{
	if (error >= 0)
	{
		ft_putstr_fd("Error - ", STDERR);
		ft_putstr_fd(strerror(errno), STDERR);
		ft_putstr_fd("\n", STDERR);
		exit(errno);
	}
	else
	{
		if (error == -1)
			ft_putstr_fd("Error - Wrong number of arguments\n", STDERR);
		else if (error == -2)
			ft_putstr_fd("Error - No .cub detected\n", STDERR);
		else if (error == -3)
			ft_putstr_fd("Error - Malloc not possible\n", STDERR);
		exit(0);
	}
}
