/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:04:38 by vpujalte          #+#    #+#             */
/*   Updated: 2023/10/02 13:37:18 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(int error, char *argument)
{
	if (error >= 0)
		exit(errno);
	else
	{
		if (error == -1)
		{
			ft_putstr_fd("minishell: ", STDERR);
			ft_putstr_fd(argument, STDERR);
			ft_putstr_fd(": No such file or directory", STDERR);
			ft_putstr_fd("\n", STDERR);
		}
		if (error == -2)
			ft_putstr_fd("minishell: Invalid number of arguments\n", STDERR);
		if (error == -3)
			ft_putstr_fd("minishell: Error at dup2\n", STDERR);
	}
}

/*
{
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(strerror(error), STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putstr_fd(argument, STDERR);
	ft_putstr_fd("\n", STDERR);
	exit(errno);
}
*/
