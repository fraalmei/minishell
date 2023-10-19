/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:09:06 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/19 18:21:00 by fraalmei         ###   ########.fr       */
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
void	signals_in_prompt(void)
{
	signal(SIGINT, signal_int);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
	signal(SIGSTOP, SIG_IGN);
}

	// dejar de ignorar las seññales
void	signals_in_process(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGTERM, SIG_DFL);
	signal(SIGSTOP, SIG_DFL);
}

int	init_signals(void)
{
	if (!g_ms->signals)
	{
		g_ms->signals = (t_sig *)ft_calloc(sizeof(t_sig), 2);
		if (!g_ms->signals)
			return (1);
		g_ms->signals->status_code = 0;
	}
	g_ms->signals->lst_stat_cod = g_ms->signals->status_code;
	g_ms->signals->status_code = 0;
	g_ms->signals->error_status = 0;
	g_ms->signals->exit_return = 0;
	return (0);
}
