/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:00:19 by fraalmei          #+#    #+#             */
/*   Updated: 2023/11/02 10:34:43 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// print the struct (or structs) generated frome the buffer
/* void	print_prompt(t_prompt *prom)
{
	int		i;

	while (prom)
	{
		ft_printf("++------------++\n");
		ft_printf("Puntero propio:		%p#\n", prom);
		ft_printf("Anterior:		%p#\n", prom->prev);
		ft_printf("Separación:		%s#\n", prom->sep0);
		ft_printf("Dirección:		%p#\n", prom);
		ft_printf("Comando:		%s#\n", prom->command);
		ft_printf("N_Opciones:		%i#\n", prom->n_options);
		if (prom->n_options > 0)
			ft_printf("Opciones:		%s#\n", prom->arguments[1]);
		ft_printf("N_Argumentos:		%d#\n", prom->n_arguments);
		i = -1;
		while (prom->arguments[++i])
			ft_printf("Argumentos:		%s		%p#\n",
				prom->arguments[i], prom->arguments[i]);
		i = -1;
		if (prom->input_redirect)
			while (prom->input_redirect[++i] != NULL)
				ft_printf("input_redirect:		%s		%p#\n",
					prom->input_redirect[i], prom->input_redirect[i]);
		i = 0;
		if (prom->output_redirect)
			while (prom->output_redirect[i] != NULL)
				ft_printf("output_redirect:		%s#\n",
					prom->output_redirect[i++]);
		ft_printf("Posición de prompt:	%i#\n", prom->pos_p);
		ft_printf("Separación:		%s#\n", prom->sep1);
		ft_printf("Siguiente:		%p#\n", prom->next);
		ft_printf("++------------++\n");
		prom = prom->next;
	}
} */

int	print_error(int error, char *str, int st_cod)
{
	ft_error(error, str);
	g_ms->signals->status_code = st_cod;
	if (str)
		free (str);
	return (0);
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
