/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:18:16 by fraalmei          #+#    #+#             */
/*   Updated: 2023/05/21 16:47:13 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// check the buffer command
int	actions(t_prompt *prompt)
{
	if (ft_strcmp(prompt->command, "exit") == 0)
		exit_shell();
	else if (ft_strcmp(prompt->command, "pwd") == 0)
		get_wd();
	else if (ft_strcmp(prompt->command, "env") == 0)
		print_env(g_mishell->envirorment, 1);
	else if (ft_strcmp(prompt->command, "export") == 0)
		export(prompt->arguments);
	/* else
		exec(buffer, g_mishell->envirorment->env); */
	return (0);
}
