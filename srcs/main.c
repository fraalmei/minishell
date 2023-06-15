/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:08:44 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/15 12:47:54 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	leaks(void)
{
	system("leaks -q minishell");
}

	// Print the prompt and call rl_on_new_line()
	// ready to read the
static int	prompt(void)
{
	signals_do();
	rl_on_new_line();
	g_ms->buffer = ft_strtrim_onefree(readline(BCYAN"minishell>"WHITE), \
		" \t\n\v\f\r");
	if (!g_ms->buffer)
		printf ("exit\n");
	else if (ft_strcmp(g_ms->buffer, "") == 0)
	{
		g_ms->prompt = NULL;
		free(g_ms->buffer);
		return (1);
	}
	else
	{
		add_history(g_ms->buffer);
		g_ms->prompt = buffer_to_list(deep_split(\
			g_ms->buffer, '|', ' '));
		//free_str (splitter(g_ms->buffer));
		//soft_split(g_ms->buffer);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	atexit(leaks);
	(void) argv;
	if (argc != 1)
		return (0);
	g_ms = (t_mini_class *)ft_calloc(sizeof(*g_ms), 1);
	if (!g_ms)
		return (0);
	g_ms->envirorment = read_env (env);
	while (prompt())
	{
		if (!g_ms->prompt)
			continue ;
		start_executer();
		free_prompt (g_ms->prompt);
	}
	free_global();
	return (0);
}
