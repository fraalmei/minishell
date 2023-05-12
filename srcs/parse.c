/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:29:45 by fraalmei          #+#    #+#             */
/*   Updated: 2023/05/12 11:18:49 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// create the prompt struct
static t_prompt	*create_prompt_struct(char *comm, char *opt, char *arg)
{
	t_prompt	*prom;

	prom = (t_prompt *)ft_calloc(sizeof(*prom), 1);
	if (!prom)
		return (NULL);
	prom->command = comm;
	prom->options = opt;
	prom->arguments = arg;
	prom->next = NULL;
	return (prom);
}

	// print the struct (or structs) generated frome the buffer
static void	print_prompt(t_prompt *prom)
{
	while (prom)
	{
		ft_printf("++------------++\n");
		ft_printf("%p\n", prom);
		ft_printf("%s\n", prom->command);
		ft_printf("%s\n", prom->options);
		ft_printf("%s\n", prom->arguments);
		ft_printf("%p\n", prom->next);
		ft_printf("++------------++\n");
		prom = prom->next;
	}
}

	// create the prompt strcut from a string of strings
static t_prompt	*str_to_promt_struct(char **str)
{
	t_prompt	*prom;
	int			i;
	char		*comm;
	char		*opt;
	char		*arg;

	i = -1;
	comm = NULL;
	opt = NULL;
	arg = NULL;
	while (str[++i])
	{
		if (i == 0)
			comm = ft_strtrim(str[i], " ");
		else if (i != 0 && ft_str_frst_cmp(str[i], "-") == 0)
			opt = ft_strjoin_onefree(ft_strjoin_onefree(opt, " "), str[i]);
		else
			arg = ft_strjoin_onefree(ft_strjoin_onefree(arg, " "), str[i]);
	}
	opt = ft_strtrim_onefree(opt, " ");
	arg = ft_strtrim_onefree(arg, " ");
	prom = create_prompt_struct(comm, opt, arg);
	return (prom);
}

t_prompt	*buffer_to_list(char ***s)
{
	char		**swap;
	t_prompt	*prom;
	t_prompt	*prom_swap;
	int			i;

	i = -1;
	prom = NULL;
	while (s[++i])
	{
		swap = s[i];
		if (i == 0)
			prom = str_to_promt_struct(swap);
		else
		{
			prom_swap = prom;
			while (prom_swap->next)
				prom_swap = prom_swap->next;
			prom_swap->next = str_to_promt_struct(swap);
		}
	}
	free_str_str (s);
	print_prompt (prom);
	return (prom);
}

	// function to split the buffer
	// to separate the function and the arguments
	// first split the buffer in pipes
	// second split the pipes in the rest of the elements
char	***deep_split(char *buffer, char c1, char c2)
{
	char	***process;
	char	**swap;
	int		i;

	swap = ft_split(buffer, c1);
	free (buffer);
	if (!swap)
		return (0);
	i = 0;
	while (swap[i])
		i++;
	process = (char ***)ft_calloc(sizeof(char ***), i + 1);
	if (!process)
		return (0);
	while (i--)
		process[i] = ft_split(swap[i], c2);
	free_str (swap);
	return (process);
}
