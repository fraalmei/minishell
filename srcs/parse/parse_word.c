/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:55:29 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/07 15:24:49 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
	printf("%s\n", word);
	return (word);
}
