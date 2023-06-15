/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:08:44 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/14 16:34:18 by fraalmei         ###   ########.fr       */
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
	g_mishell->buffer = ft_strtrim_onefree(readline(BCYAN"minishell>"WHITE), \
		" \t\n\v\f\r");
	if (!g_mishell->buffer)
		printf ("exit\n");
	else if (ft_strcmp(g_mishell->buffer, "") == 0)
	{
		g_mishell->prompt = NULL;
		free(g_mishell->buffer);
		return (1);
	}
	else
	{
		add_history(g_mishell->buffer);
		g_mishell->prompt = buffer_to_list(deep_split(\
			g_mishell->buffer, '|', ' '));
		//free_str (splitter(g_mishell->buffer));
		soft_split(g_mishell->buffer);
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
	g_mishell = (t_mini_class *)ft_calloc(sizeof(*g_mishell), 1);
	if (!g_mishell)
		return (0);
	g_mishell->envirorment = read_env (env);
	while (prompt())
	{
		if (!g_mishell->prompt)
			continue ;
		actions(g_mishell->prompt);
		free_prompt (g_mishell->prompt);
	}
	free_global();
	return (0);
}
