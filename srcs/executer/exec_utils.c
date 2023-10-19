/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:28:45 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/19 16:51:33 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <executer.h>

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
	if (!ft_strncmp(arg, "pwd", 3))
		return (1);
	else if (!ft_strncmp(arg, "cd", 2))
		return (1);
	else if (!ft_strncmp(arg, "echo", 4))
		return (1);
	else if (!ft_strncmp(arg, "env", 3))
		return (1);
	else if (!ft_strncmp(arg, "export", 6))
		return (1);
	else if (!ft_strncmp(arg, "unset", 5))
		return (1);
	else if (!ft_strncmp(arg, "exit", 4))
		return (1);
	else
		return (0);
}

void	ft_set_errstatus(int state)
{
	if (WIFSIGNALED(state))
		g_ms->signals->status_code = WTERMSIG(state) + 128;
	else if (WIFSTOPPED(state))
		g_ms->signals->status_code = WSTOPSIG(state);
	else if (WIFEXITED(state))
		g_ms->signals->status_code = WEXITSTATUS(state);
}
