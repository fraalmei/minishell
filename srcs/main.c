/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:08:44 by fraalmei          #+#    #+#             */
/*   Updated: 2023/09/08 17:49:41 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	leaks(void)
{
	system("leaks -q minishell");
}

/// @brief initialize the signals, create the prompt and wait the data,
/// check the data, if the is data procces it, add history, transform the data
/// and free the buffer
/// @param  none use the global variable g_ms
/// @return 1 if the function works correctly, 0 if not
int	prompt(void)
{
	signals_do();
	rl_on_new_line();
	g_ms->buffer = ft_strtrim_onefree(readline(BCYAN"minishell>"WHITE), \
		" \t\n\v\f\r");
	if (!g_ms->buffer)
		(printf ("exit\n"), exit_shell());
	else if (ft_strcmp(g_ms->buffer, "") == 0)
	{
		g_ms->prompt = NULL;
		free(g_ms->buffer);
		g_ms->buffer = NULL;
		return (1);
	}
	else
	{
		add_history(g_ms->buffer);
		g_ms->prompt = buffer_to_prompt(g_ms->buffer, g_ms->prompt);
		print_prompt(g_ms->prompt);
		free (g_ms->buffer);
		g_ms->buffer = NULL;
		return (1);
	}
	return (0);
}

/// @brief initiate the global structure
/// @param argc number of arguments introduced
/// but the progran must not need arguments
/// @param env the envirorment variables of the father system
/// @return 0 if it works correctly, 1 if an error occur
static int	init_global(int argc, char **env)
{
	if (argc != 1)
		return (printf("No arguments required\n"), 1);
	g_ms = (t_mini_class *)ft_calloc(sizeof(*g_ms), 2);
	if (!g_ms)
		return (1);
	g_ms->envirorment = read_env(env);
	return (0);
}

/// @brief

/// @return 0 if it works correctly, 1 if an error occur
int	main(int argc, char **argv, char **env)
{
	atexit(leaks);
	(void) argv;
	if (init_global(argc, env))
		return (1);
	if (init_signals())
		return (1);
	while (prompt())
	{
		if (!g_ms->prompt)
			continue ;
		//actions(g_ms->prompt);
		start_executer();
		free_prompt(g_ms->prompt);
		g_ms->prompt = NULL;
	}
	free_global();
	return (0);
}

	//system("leaks -q minishell");
