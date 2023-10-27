/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:55:29 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/27 13:32:54 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	read_word_simple_q_off(char **word)
{
	char	*swap;

	swap = *word;
	if (swap[0] == 39 && swap[0] == swap[ft_strlen(swap) - 1])
	{
		*word = ft_strtrim_onefree(swap, "'");
		return (1);
	}
	return (0);
}

/// @brief Return the value of a variable or an empty string
/// from the command buffer.
/// This function is responsible for extracting the value of a variable
/// from the command buffer
/// or returning an empty string if the variable is not found.
/// It is typically used to handle
/// variable expansion within the command buffer.
/// @param buffer The original command buffer containing variables.
/// @param i A pointer to the iterator position in the original command buffer.
/// @return The value of the variable or an empty string
/// if the variable is not found.
/// @note The function expects `buffer` to contain the command with variables.
/// @note It updates `i` to the next position after the variable.
/// @note The function relies on helper functions
/// like `ft_chrcmp_env_forbid`, `ft_substr`,
/// and `get_value` to identify and retrieve variable values.
char	*return_wild(char *buffer, int *i)
{
	int		x;
	char	*name;
	char	*value;

	i[0]++;
	x = ft_chrcmp_env_forbid(&buffer[*i]);
	if (x == 0)
		return ("$");
	name = ft_substr(buffer, *i, x);
	value = get_value(g_ms->envirorment->frst, name);
	free (name);
	*i += x;
	if (!value)
		return ("");
	return (value);
}

/// @brief Read and extract a word from the command buffer.
/// This function reads a word from the command buffer
/// starting at the specified position (i) and
/// returns the extracted word as a dynamically allocated string.
/// A word is defined as a sequence of characters
/// that are not spaces or redirection symbols.
/// @param buffer The original command buffer containing words and symbols.
/// @param i A pointer to the iterator position in the original command buffer.
/// @return A dynamically allocated string containing the extracted word.
/// @note The function expects `buffer`
/// to contain the command with words and symbols.
/// @note It updates `i` to the next position after the extracted word.
/// @note The function handles both single and double quotes
/// as well as redirection symbols.
char	*read_word(char *buffer, int *i)
{
	char	*word;
	char	c;

	word = (char *)ft_calloc(sizeof(char), 2);
	while (buffer[*i] && buffer[*i] != ' ' && is_redirecction(&buffer[*i]) == 0)
	{
		if (buffer[*i] == 39 || buffer[*i] == 34)
		{
			c = buffer[*i];
			i[0]++;
			while (buffer[*i] && buffer[*i] != c)
				word = ft_chrjoin(word, buffer[i[0]++]);
		}
		else
			word = ft_chrjoin(word, buffer[*i]);
		i[0]++;
	}
	return (word);
}
