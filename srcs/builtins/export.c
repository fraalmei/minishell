/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:39:59 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/19 11:02:44 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// imprime el export
static void	print_export(t_env_var	*env)
{
	ft_printf("declare -x %s", env->name);
	if (env->equal)
	{
		ft_printf("=");
		if (env->value)
			ft_printf("\"%s\"\n", env->value);
		else
			ft_printf("\"\"\n");
	}
	else
		ft_printf("\n");
}

static t_env_var	*get_less_node(t_env_var *list, t_env_var *last)
{
	t_env_var	*ret;

	if (!last)
	{
		ret = list;
		while (list)
		{
			if (ft_strcmp(ret->name, list->name) >= 0)
				ret = list;
			list = list->next;
		}
		return (ret);
	}
	ret = NULL;
	while (list)
	{
		if (ft_strcmp(last->name, list->name) < 0)
		{
			if (!ret)
				ret = list;
			else if (ft_strcmp(ret->name, list->name) >= 0)
				ret = list;
		}
		list = list->next;
	}
	return (ret);
}

static void	print_sort_list(t_env_var *list)
{
	t_env_var	*swap;
	int			i;

	i = list_len(list);
	swap = get_less_node(list, NULL);
	print_export (swap);
	while (--i > 0)
	{
		swap = get_less_node(list, swap);
		print_export(swap);
	}
	swap = get_less_node(list, swap);
	print_export(swap);
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
	int			i[2];

	splt = NULL;
	if (prompt->n_options == 0 && prompt->n_arguments == 1)
		return (print_sort_list(g_ms->envirorment->frst), 0);
	else if (prompt->n_options != 0)
		return (print_error(prompt->arguments[0], 2), 0);
	i[0] = 0;
	while (prompt->arguments[++i[0]])
	{
		i[1] = 0;
		if (!prompt->arguments[i[0]])
			return (0);
		if (ft_str_chr(prompt->arguments[i[0]], '=') != 0)
			splt = ft_split(prompt->arguments[i[0]], '=');
		else
			(print_error(prompt->arguments[i[0]], 1), i[1]++);
		if (ft_str_chr(splt[0], ' ') > 0 && !splt[1] && i[1] == 0)
			return (print_error(NULL, 1), free_str(splt), 0);
		else if (ft_str_chr(splt[0], ' ') > 0 && i[1] == 0)
			return (print_error(splt[1], 1), free_str(splt), 0);
		set_value(&g_ms->envirorment->frst, prompt->arguments[i[0]]);
		free_str(splt);
	}
	return (0);
}
