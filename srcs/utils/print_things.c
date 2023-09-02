/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:00:19 by fraalmei          #+#    #+#             */
/*   Updated: 2023/09/02 10:33:46 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// print the struct (or structs) generated frome the buffer
void	print_prompt(t_prompt *prom)
{
	int		i;

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
		i = 0;
		if (prom->here_doc)
			while (prom->here_doc[i] != NULL)
				ft_printf("here_doc:	%s#\n", prom->here_doc[i++]);
		i = 0;
		if (prom->input_redirect)
			while (prom->input_redirect[i] != NULL)
				ft_printf("input_redirect:	%s#\n", prom->input_redirect[i++]);
		i = 0;
		if (prom->output_redirect)
			while (prom->output_redirect[i] != NULL)
				ft_printf("output_redirect:	%s#\n", prom->output_redirect[i++]);
		i = 0;
		if (prom->append_redirect)
			while (prom->append_redirect[i] != NULL)
				ft_printf("append_redirect:	%s#\n", prom->append_redirect[i++]);
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
