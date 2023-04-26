/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: p <p@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:29:45 by fraalmei          #+#    #+#             */
/*   Updated: 2023/04/22 09:30:23 by p                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* static int	print_deep_split(char ***s)
{
	char	**swap;
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		ft_printf("--------------------------------\n");
		swap = s[i];
		j = 0;
		while (swap[j])
			ft_printf("%s\n", swap[j++]);
		i++;
	}
	return (0);
} */

static t_prompt	*create_prompt_struct(char *comm, char *opt, char *arg)
{
	t_prompt	*prom;

	prom = (t_prompt *)ft_calloc(sizeof(t_prompt *), 1);
	prom->command = comm;
	prom->options = opt;
	prom->arguments = arg;
	prom->next = NULL;
	return (prom);
}

static void	print_prompt(t_prompt *prom)
{
	ft_printf("%s\n", prom->command);
	ft_printf("%s\n", prom->options);
	ft_printf("%s\n", prom->arguments);
	ft_printf("%p\n", prom->next);
}

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
	/* if (opt != NULL)
		opt = ft_strtrim_onefree(opt, " ");
	if (arg != NULL)
		arg = ft_strtrim_onefree(arg, " "); */
	prom = create_prompt_struct(comm, opt, arg);
	print_prompt(prom);
	return (prom);
}

t_prompt	*prompt_to_list(char ***s)
{
	char		**swap;
	t_prompt	*prom;
	t_prompt	*swap_prom;
	int			i;

	i = -1;
	swap_prom = NULL;
	prom = NULL;
	while (s[++i])
	{
		swap = s[i];
		if (i == 0)
		{
			prom = str_to_promt_struct(swap);
		}
		else
		{
			swap_prom = str_to_promt_struct(swap);
		}
	}
	ft_printf("ha petado aqui?\n");
	//free_str_str (s);
	return (prom);
}

	// function to split the buffer
	// to separate the function and the arguments
	// first split the buffer in pipes
	// second split the pipes in the rest of the elements
char	***deep_split(const char *buffer, char c1, char c2)
{
	char	***process;
	char	**swap;
	int		i;

	swap = ft_split(buffer, c1);
	if (!swap)
		return (0);
	i = 0;
	while (swap[i])
		i++;
	process = (char ***)ft_calloc(sizeof(char **), i);
	if (!process)
		return (0);
	while (i--)
	{
		process[i] = ft_split(swap[i], c2);
		free (swap[i]);
	}
	free (swap);
	//print_deep_split(process);
	return (process);
}
