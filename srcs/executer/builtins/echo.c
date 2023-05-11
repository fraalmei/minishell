/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:18:06 by cagonzal          #+#    #+#             */
/*   Updated: 2023/04/17 14:58:47 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_echo(char **arg)
{
	int	i;
	int	j;
	int	newline;

	newline = 1;
	i = 1;
	if (!arg[1])
	{
		ft_putstr_fd("\0", 1);
		ft_putstr_fd("\n", 1);
		return ;
	}
	while (arg[i])
	{
		j = 0;
		if (arg[i][j])
		{
			ft_putstr_fd(&arg[i][j], FD_OUT);
			j++;
		}
		i++;
	}
	if (newline == 1)
		ft_putstr_fd("\n", FD_OUT);
}
