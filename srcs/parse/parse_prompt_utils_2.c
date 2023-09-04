/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prompt_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:55:29 by fraalmei          #+#    #+#             */
/*   Updated: 2023/09/04 16:08:51 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <minishell.h>

int	swap_word(char *string, char **word, char **swap, int *i, char c)
{
	if (string[*i] == '$' && string[*i + 1] == '?')
	{
		*word = ft_chrjoin(*word, string[*i]);
		*word = ft_chrjoin(*word, string[*i + 1]);
		*i += 2;
	}
	/* else if (string[*i] == '$' && string[*i + 1] == '$')
	{
		*i += 2;
	} */
	else if (string[*i] == '$' && (c == 34 || c == '\0'))
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

int	option_gen(t_prompt *prm, char *st, int *i)
{
	int		x[2];

	if (!prm->arguments[1])
		prm->arguments[1] = (char *)ft_calloc(sizeof(char), 2);
	if (!prm->arguments[1])
		return (-1);
	x[0] = 0;
	x[1] = ft_strlen(prm->arguments[1]);
	while (st[*i] && is_redirecction(&st[*i]) == 0 && st[*i] != ' ')
	{
		if (st[*i] == '-' && x[0] < 1)
			x[0]++;
		else if (x[0] > 1)
		{
			g_ms->signals->error_status = 1;
			return (printf("illegal option -- -\n"), -1);
		}
		else if (!ft_strrchr(prm->arguments[1], st[*i]))
			prm->arguments[1] = (x[1]++, ft_chrjoin(prm->arguments[1], st[*i]));
		*i += 1;
	}
	return (x[1]);
}
