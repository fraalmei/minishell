/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prompt_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:55:29 by fraalmei          #+#    #+#             */
/*   Updated: 2023/09/29 19:07:48 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	swap_word(char *buffer, char **word, int *i)
{
	static char	*swap;

	swap = return_wild(buffer, &*i);
	*i += 1;
	if (swap)
		*word = ft_strjoin_onefree(*word, swap);
	return (0);
}

int	reading_word(char *buffer, char **word, int *i, char c)
{
	if (buffer[*i] == '$' && buffer[*i + 1] == '?')
	{
		*word = ft_strjoin_allfree(*word, ft_itoa(g_ms->signals->lst_stat_cod));
		*i += 2;
	}
	else if (buffer[*i] == '$' && (c == 34 || c == '\0'))
	{
		if (buffer[*i + 1] == '{')
		{
			if (ft_str_chr(&buffer[*i + 1], '}') < 0)
				return (printf("}: bad substitution\n"), -1);
			*i += 1;
			swap_word(buffer, word, i);
			*i += 1;
		}
		else
			swap_word(buffer, word, i);
	}
	else
	{
		*word = ft_chrjoin(*word, buffer[*i]);
		*i += 1;
	}
	return (0);
}

char	*read_word(char *buffer, int *i)
{
	char	*word;
	char	c;

	word = (char *)ft_calloc(sizeof(char), 2);
	while (buffer[*i] && buffer[*i] != ' ' && is_redirecction(&buffer[*i]) == 0)
	{
		c = '\0';
		if (buffer[*i] == 39 || buffer[*i] == 34)
		{
			c = buffer[*i];
			*i += 1;
			if (reading_word(buffer, &word, i, c) != 0)
				return (g_ms->signals->status_code++, free(word), NULL);
			*i += 1;
		}
		else
			if (reading_word(buffer, &word, i, c) != 0)
				return (g_ms->signals->status_code++, free(word), NULL);
	}
	*i -= 1;
	return (word);
}
