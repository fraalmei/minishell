/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:39:59 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/05 11:22:41 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// export ->muestra las variables de entorno en orden alfabetico
	// export - (con el guion de las flags)-> lo mismo que arriba
	// export -a ->lo mismo de arriba añadiendo despues las variables ocultas
	// export -ajqndjn -> omite las 'a' y muestra "export: bad option: -j" 
			// (- + la primera letra despues de las as)
	// export -p ->igual que arriba pero añadiedo export delante de resultado
	// export -p nombre -> muestra el contenido de la variable
	// export nombre -> no hace nada
	// export nombre= -> guarda el nombre sin valor
	// export nombre=valor -> guarda el nombre con el valor 
			// o sustituye el valor si ya existe el nombre
	// export nombre=valor -> guarda el nombre y el valor
	// export nombre= valor -> guarda el nombre sin valor
	// export nombre =valor -> zsh: ioajsd not found
	// export nombre = -> zsh: bad assignment
int	export(t_prompt *prompt)
{
	char		**splt;

	printf("entra\n");
	if (!prompt->options && !prompt->arguments)
		return (print_env(g_mishell->envirorment->s_frst, 1), 0);
	else if (prompt->options)
		return (printf("bad option: %s\n", prompt->options), 0);
	if (!prompt->arguments)
		return (0);
	splt = ft_split(prompt->arguments, '=');
	if (ft_str_lst_chr(splt[0], ' ') > 0 && !splt[1])
		return (printf("bad assigment\n"), free_str(splt), 0);
	else if (ft_str_lst_chr(splt[0], ' ') > 0)
		return (printf("%s not found\n", splt[1]), free_str(splt), 0);
	if (get_name(g_mishell->envirorment->s_frst, splt[0]) && \
			get_name(g_mishell->envirorment->frst, splt[0]))
	{
		printf("actions set\n");
		(set_value(g_mishell->envirorment->frst, splt), \
			set_value(g_mishell->envirorment->s_frst, splt));
	}
	else
	{
		lst_strct_env(g_mishell->envirorment->frst)->next = \
			new_struct_env(splt);
		sort_in_list(&g_mishell->envirorment->s_frst, \
			new_struct_env(ft_split(prompt->arguments, '=')));
	}
	return (0);
}
