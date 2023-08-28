/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prompt_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:55:29 by fraalmei          #+#    #+#             */
/*   Updated: 2023/08/28 13:20:06 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <minishell.h>

int	swap_word(char *string, char **word, char **swap, int *i, char c)
{
	if (string[*i] == '$' && (c == 34 || c == '\0'))
	{
		*swap = return_wild(string, &*i);
		*i += 1;
		if (swap)
			*word = ft_strjoin_onefree(*word, *swap);
	}
	else
	{
		*word = ft_chrjoin(*word, string[*i]);
		*i += 1;
	}
	return (0);
}

char	*read_word(char *string, int *i)
{
	char	*word;
	char	*swap;
	char	c;

	word = (char *)ft_calloc(sizeof(char), 2);
	while (string[*i] && string[*i] != ' ' && is_redirecction(&string[*i]) == 0)
	{
		c = '\0';
		if (string[*i] == 39 || string[*i] == 34)
		{
			c = string[*i];
			*i += 1;
			while (string[*i] && string[*i] != c)
				swap_word(string, &word, &swap, i, c);
			*i += 1;
		}
		else
			swap_word(string, &word, &swap, i, c);
	}
	*i -= 1;
	return (word);
}

int	option_gen(t_prompt *prom, char *str, int *i)
{
	int		l;
	int		x;

	printf("entra opciones\n");
	if (!prom->arguments)
	{
		prom->arguments = (char **)ft_calloc(sizeof(char *), 2);
		prom->arguments[0] = (char *)ft_calloc(sizeof(char), 2);
	}
	if (!prom->arguments || !prom->arguments[0])
		return (-1);
	x = 0;
	l = ft_strlen(prom->arguments[0]);
	while (str[*i] && is_redirecction(&str[*i]) == 0 && str[*i] != ' ')
	{
		if (str[*i] == '-' && x < 1)
			x++;
		else if (x > 1)
		{
			g_ms->signals->error_status = 1;
			return (printf("illegal option -- -\n"), -1);
		}
		else if (!ft_strrchr(prom->arguments[0], str[*i]))
			prom->arguments[0] = (l++, ft_chrjoin(prom->arguments[0], str[*i]));
		*i += 1;
	}
	return (l);
}
