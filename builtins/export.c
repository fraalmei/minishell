/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:39:59 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/06 13:09:35 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// imprime el export
static void	print_export(t_env_var	*env)
{
	while (env)
	{
		ft_printf("declare -x %s", env->name);
		ft_printf("=");
		if (env->value)
			ft_printf("\"%s\"\n", env->value);
		else
			ft_printf("\"\"\n");
		env = env->next;
	}
}

	// export ->muestra las variables de entorno en orden alfabetico
	// export nombre -> guarda el nombre sin valor en export
	// export nombre= -> guarda el nombre sin valor
	// export nombre=valor -> guarda el nombre con el valor 
			// o sustituye el valor si ya existe el nombre
	// export nombre=valor -> guarda el nombre y el valor en env y export
	// export nombre= valor -> guarda el nombre sin valor en env y export
	// export nombre =valor -> bash: export: `=valor': not a valid identifier
	// export nombre = -> zsh: bad assignment
int	export(t_prompt *prompt)
{
	char		**splt;

	printf("entra\n");
	if (!prompt->options && !prompt->arguments)
		return (print_export(g_mishell->envirorment->s_frst), 0);
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
