/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:00:19 by fraalmei          #+#    #+#             */
/*   Updated: 2023/08/28 11:43:35 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// print the struct (or structs) generated frome the buffer
void	print_prompt(t_prompt *prom)
{
	int		i;

	ft_printf("Cosas\n");
	while (prom)
	{
		ft_printf("++------------++\n");
		ft_printf("Puntero propio:	%p#\n", prom);
		ft_printf("Anterior:	%p#\n", prom->prev);
		ft_printf("Separación:	%s#\n", prom->sep0);
		ft_printf("Dirección:	%p#\n", prom);
		ft_printf("Comando:	%s#\n", prom->command);
		ft_printf("N_Opciones:	%i#\n", prom->n_options);
		if (prom->n_options > 0)
		{
			ft_printf("Opciones:	%s#\n", prom->arguments[0]);
			i = 0;
		}
		else
			i = -1;
		ft_printf("N_Argumentos:	%d#\n", prom->n_arguments);
		if (prom->n_arguments > 0)
		{
			while (++i < prom->n_arguments)
				ft_printf("Argumentos:	%s#\n", prom->arguments[i]);
		}
		else
			ft_printf("Argumentos:	(null)#\n");
		ft_printf("Separación:	%s#\n", prom->sep1);
		ft_printf("Siguiente:	%p#\n", prom->next);
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
