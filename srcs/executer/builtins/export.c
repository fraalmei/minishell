/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:18:47 by cagonzal          #+#    #+#             */
/*   Updated: 2023/04/26 14:50:15 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_export(t_lst *arg)
{
	int		i;

	i = 0;
	if (!arg->str_arg || arg->str_arg[0] == '\0')
		print_env();
	else
		ft_export_logic(arg);
}

void	ft_export_logic(t_lst *arg)
{
	char	*name;
	char	*value;

	name = strtok(arg, "=");
	value = strtok(NULL, "=");

	if (name == NULL || value == NULL)
	{
		printf("Error: argumento inválido para export.\n");
		return (1);
	}
}
