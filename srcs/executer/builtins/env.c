/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:18:32 by cagonzal          #+#    #+#             */
/*   Updated: 2023/04/20 12:44:28 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_env(void)
{
	int		i;
	char	*name;

	i = 0;
	while (g_ms->sh_env[i])
	{
		name = ft_getname(g_ms->sh_env[i]);
		if (*(g_ms->sh_env[i] + ft_strlen(name) + 1) != '\\')
			printf("%s\n", g_ms->sh_env[i]);
		free(name);
		i++;
	}
}
