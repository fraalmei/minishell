/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:08:44 by fraalmei          #+#    #+#             */
/*   Updated: 2023/05/13 10:07:21 by fraalmei         ###   ########.fr       */
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
	t_prompt	*prom;
	char		*buffer;

	signals_do();
	rl_on_new_line();
	buffer = ft_strtrim_onefree(readline(BCYAN"minishell>"WHITE), " ");
	if (!buffer)
		printf ("exit\n");
	else if (!ft_strnstr(buffer, "exit", ft_strlen(buffer)))
	{
		ft_printf("%s\n", buffer);
		prom = buffer_to_list(deep_split(buffer, '|', ' '));
		free_prompt (prom);
		return (1);
	}
	free (buffer);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_env	*mini_env;

	atexit(leaks);
	(void) argv;
	if (argc != 1)
		exit(0);
	mini_env = read_env (env);
	while (prompt())
	{
	}
	free_env (mini_env);
	return (0);
}
