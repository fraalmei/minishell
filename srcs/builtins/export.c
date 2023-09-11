/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:39:59 by fraalmei          #+#    #+#             */
/*   Updated: 2023/09/11 12:07:36 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// imprime el export
static void	print_export(t_env_var	*env)
{
	ft_printf("declare -x %s", env->name);
	if (env->equal)
		ft_printf("=");
	if (env->value)
		ft_printf("\"%s\"\n", env->value);
	else
		ft_printf("\"\"\n");
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
	}
	else
	{
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
	while (--i)
	{
		swap = get_less_node(list, swap);
		print_export(swap);
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
	int			i;

	splt = NULL;
	if (prompt->n_options == 0 && prompt->n_arguments == 1)
		return (print_sort_list(g_ms->envirorment->frst), 0);
	else if (prompt->n_options != 0)
		return (printf("bad option: %s\n", prompt->arguments[0]), 0);
	i = 0;
	while (prompt->arguments[++i])
	{
		if (!prompt->arguments[i])
			return (0);
		if (ft_str_chr(prompt->arguments[i], '=') >= 0)
			splt = ft_split(prompt->arguments[i], '=');
		if (ft_str_lst_chr(splt[0], ' ') > 0 && !splt[1])
			return (printf("bad assigment\n"), free_str(splt), 0);
		else if (ft_str_lst_chr(splt[0], ' ') > 0)
			return (printf("%s not found\n", splt[1]), free_str(splt), 0);
		if (get_name(g_ms->envirorment->frst, splt[0]))
		{
			printf("actions set\n");
			set_value(g_ms->envirorment->frst, prompt->arguments[i]);
		}
		else
			lst_strct_env(g_ms->envirorment->frst)->next = \
				new_struct_env(prompt->arguments[i]);
	}
	return (0);
}
