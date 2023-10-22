/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:04:38 by vpujalte          #+#    #+#             */
/*   Updated: 2023/10/21 21:57:29 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(int error, char *argument)
{
	if (error == -1)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(argument, STDERR);
		ft_putstr_fd(": command not found\n", STDERR);
	}
	else if (error == -2)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(" error in dup2\n", STDERR);
	}
	else if (error == -3)
	{
		ft_putstr_fd("minishell: cd: ", STDERR);
		ft_putstr_fd(argument, STDERR);
		ft_putstr_fd(" No such file or directory\n", STDERR);
	}
	else if (error == -4)
		ft_putstr_fd("minishell: Error at dup2\n", STDERR);
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
