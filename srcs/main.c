/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:08:44 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/27 11:50:14 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	leaks(void)
{
	system("leaks -q minishell");
}

int	prompt(char **buffer)
{
	rl_on_new_line();
	*buffer = readline(BCYAN"mminishell>"WHITE);
	add_history(*buffer);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*buffer;

	atexit(leaks);
	buffer = (char *)ft_calloc(sizeof(char *), 1);
	if (argc != 1 || argv[1])
	{
		ft_printf("This program does not accept arguments\n");
		exit(0);
	}
	while (!(ft_strnstr(buffer, "exit", 4)))
	{
		prompt(&buffer);
		ft_printf("%s\n", buffer);
		ft_printf("intentas hacer cosas.\n");
	}
	free(buffer);
	return (0);
}

/*
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
	char *input;

	// Imprime el prompt y llama a rl_on_new_line() para indicar 
	// que estamos listos para leer la entrada del usuario
	rl_on_new_line();
	input = readline("Ingrese un texto: ");
	// Agrega la entrada del usuario al historial de comandos
	add_history(input);
	// Imprime la entrada del usuario por pantalla
	printf("Ingresaste: %s\n", input);
	// Libera la memoria reservada por readline()
	//free(input);
	return 0;
}
*/