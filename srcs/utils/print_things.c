/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:00:19 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/19 13:24:22 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// print the struct (or structs) generated frome the buffer
void	print_prompt(t_prompt *prom)
{
	while (prom)
	{
		ft_printf("++------------++\n");
		ft_printf("Puntero propio:	%p\n", prom);
		ft_printf("Anterior:	%p\n", prom->prev);
		ft_printf("Separación:	%s\n", prom->sep0);
		ft_printf("Dirección:	%p\n", prom);
		ft_printf("Comando:	%s\n", prom->command);
		ft_printf("Opciones:	%s\n", prom->options);
		ft_printf("Argumentos:	%s\n", prom->arguments);
		ft_printf("Separación:	%s\n", prom->sep1);
		ft_printf("Siguiente:	%p\n", prom->next);
		ft_printf("++------------++\n");
		prom = prom->next;
	}
}

void	print_str_str(char **string)
{
	int		i;

	i = 0;
	while (string[i])
	{
		printf("%s\n", string[i]);
		i++;
	}
}
