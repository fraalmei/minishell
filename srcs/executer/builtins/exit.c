/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:18:38 by cagonzal          #+#    #+#             */
/*   Updated: 2023/04/17 12:53:13 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_exit(char **args, int call)
{
	int		is_num;

	if (call == 1)
		ft_putstr_fd("exit\n", 2);
	if (!args[1])
		exit(0);
	is_num = check_if_digit(args[1]);
	if (!is_num)
		exit(255);
	else
	{
		if (!args[2])
			exit(ft_atoi(args[1]));
	}
}

int	check_if_digit(const char *str)
{
	int		is_num;
	size_t	i;

	is_num = 1;
	i = 0;
	if (!str)
		return (0);
	while (str[i] && is_num)
		if (!ft_isdigit(str[i++]))
			is_num = 0;
	return (is_num && i > 0);
}
