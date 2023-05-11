/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:08:44 by fraalmei          #+#    #+#             */
/*   Updated: 2023/05/10 14:30:38 by fraalmei         ###   ########.fr       */
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
	buffer = readline(BCYAN"minishell>"WHITE);
	if (!ft_strnstr(buffer, "exit", ft_strlen(buffer)) && \
		ft_strncmp(buffer, "\n", ft_strlen(buffer)))
	{
		ft_printf("%s\n", buffer);
		prom = buffer_to_list(deep_split(buffer, '|', ' '));
		free_prompt (prom);
		return (1);
	}
	else if (ft_strnstr(buffer, "exit", ft_strlen(buffer)))
	{
		free (buffer);
		exit (0);
	}
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	atexit(leaks);
	(void) argv;
	(void) env;
	if (argc != 1)
		exit(0);
	while (1)
	{
		prompt();
	}
	return (0);
}
