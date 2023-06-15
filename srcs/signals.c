/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:09:06 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/08 14:47:07 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/// @brief function to action when the signal its called
/// @param code signal code not used but needed to create the function
static void	signal_int(int code)
{
	(void) code;
	ft_printf(BCYAN"minishell>");
	ft_printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

	// signals control
	// SIGINT => ctrl-C
	// SIGTSTP => ctrl-Z
/// @brief calling the main signals to asign an action when they're called
/// @param  no need
void	signals_do(void)
{
	signal(SIGINT, signal_int);
	//signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
	signal(SIGSTOP, SIG_IGN);
}

void	init_signals(void)
{
	t_sig	*signals;

	signals = NULL;
	signals = (t_sig *)ft_calloc(sizeof(*signals), 1);
	signals->exit_status = 0;
	signals->exit_return = 0;
}
