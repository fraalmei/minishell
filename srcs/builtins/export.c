/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:39:59 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/27 13:55:44 by fraalmei         ###   ########.fr       */
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

static t_env_var	*prtlssnd(t_env_var *list, t_env_var *last, t_env_var *ret)
{
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
	swap = prtlssnd(list, NULL, NULL);
	print_export (swap);
	while (--i > 0)
	{
		swap = prtlssnd(list, swap, NULL);
		print_export(swap);
	}
	swap = prtlssnd(list, swap, NULL);
	print_export(swap);
}

static int	check_args(char **args, int *i)
{
	char		**splt;

	splt = NULL;
	if (!args[*i])
		return (1);
	else if (args[*i][0] == '=')
		return (print_error(ft_strdup(args[*i]), 1));
	else if (ft_str_chr(args[*i], '=') != 0)
		splt = ft_split(args[*i], '=');
	else
	{
		print_error(args[*i], 1);
		return (0);
	}
	if (ft_str_chr(splt[0], ' ') > 0 && !splt[1])
		return (print_error(NULL, 1), free_str(splt), 1);
	else if (ft_str_chr(splt[0], ' ') > 0)
		return (print_error(splt[1], 1), free_str(splt), 1);
	if (args[*i][0] != '_' && args[*i][1] != '=')
		set_value(&g_ms->envirorment->frst, args[*i]);
	free_str(splt);
	return (0);
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
	int			i;
	int			e;

	if (prompt->n_options == 0 && prompt->n_arguments == 1)
		return (print_sort_list(g_ms->envirorment->frst), 0);
	else if (prompt->n_options != 0)
		return (print_error(prompt->arguments[0], 2), 0);
	i = 0;
	while (prompt->arguments[++i])
	{
		e = check_args(prompt->arguments, &i);
		if (e)
			return (e);
	}
	return (0);
}
