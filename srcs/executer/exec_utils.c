/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:28:45 by cagonzal          #+#    #+#             */
/*   Updated: 2023/08/17 16:42:11 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_lstpromptsize(t_prompt *lst)
{
	unsigned int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	is_builtin(char *arg)
{
	if (ft_strncmp(arg, "pwd", 3))
		return (1);
	else if (ft_strncmp(arg, "cd", 2))
		return (1);
	else if (ft_strncmp(arg, "echo", 4))
		return (1);
	else if (ft_strncmp(arg, "env", 3))
		return (1);
	else if (ft_strncmp(arg, "export", 6))
		return (1);
	else if (ft_strncmp(arg, "unset", 5))
		return (1);
	else if (ft_strncmp(arg, "exit", 4))
		return (1);
	else
		return (0);
}
