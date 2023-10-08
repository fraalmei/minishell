/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sustitution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:13:46 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/08 05:04:58 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/// @brief Compares characters in a string to determine if any
/// forbidden characters are present.
/// This function iterates through the characters in the given string 
/// and checks if each character is an alphanumeric character (letters / digits)
/// or an underscore (ASCII 95). If a forbidden character is encountered,
/// the function returns the position of that character in the string.
/// @param str A pointer to the null-terminated string to be checked.
/// @return The position of the first forbidden character encountered,
/// or the length of the string if no forbidden characters are found.
static int	ft_chrcmp_env_forbid(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != 95)
			return (i);
		i++;
	}
	return (i);
}

static int	ft_check_dolar_redir(char *buffer, int i)
{
	int		x;
	char	*name;

	if (is_redir(&buffer[i]) == 0)
		return (0);
	else if (is_redir(&buffer[i]) > 0 && ((buffer[i] == '<' && \
		buffer[i + 1] == '<') || (buffer[i] == '<' && buffer[i - 1] == '<')))
		return (0);
	else
		i += is_redir(&buffer[i]);
	ignore_no_p(buffer, &i);
	if (buffer[i] == '$')
	{
		i++;
		x = ft_chrcmp_env_forbid(&buffer[i]);
		if (x == 0)
			name = "";
		else
			name = ft_substr(buffer, i, x);
		if (ft_str_chr(get_value(g_ms->envirorment->frst, name), ' ') >= 0)
			return (print_error(name, 11), -1);
	}
	return (0);
}

static int	ft_check_heredoc_no_sust(char *buffer, int *i, char **swap)
{
	int		l;
	int		sw;

	if (is_redir(&buffer[*i]) == 2 && ((buffer[*i] == '<' && \
		buffer[*i + 1] == '<') || (buffer[*i] == '<' && buffer[*i - 1] == '<')))
		l = is_redir(&buffer[*i]);
	else
		return (0);
	sw = *i + l;
	ignore_no_p(buffer, &sw);
	if (buffer[sw] == '$')
	{
		sw++;
		l = ft_chrcmp_env_forbid(&buffer[sw]);
		sw += l;
		while (*i != sw)
			*swap = ft_chrjoin(*swap, g_ms->buffer[i[0]++]);
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
		return ("");
	name = ft_substr(buffer, *i, x);
	value = get_value(g_ms->envirorment->frst, name);
	free (name);
	*i += x;
	if (!value)
		return ("");
	return (value);
}

/// @brief Handle quoted sections within the command buffer.
/// This function is responsible for processing quoted sections
/// within the command buffer.
/// It identifies the type of quote (single or double),
/// preserves the quoted content, and
/// handles variable expansion within the quoted sections.
/// @param buffer The original command buffer containing quoted sections.
/// @param swap A pointer to the temporary buffer
/// for storing the updated command.
/// @param i A pointer to the iterator position in the original command buffer.
/// @note The function expects `buffer`
/// to contain the command with quoted sections.
/// @note It updates `swap` with the processed content.
/// @note The function relies on helper functions like `ft_chrjoin`,
/// `ft_strjoin_onefree`,
/// and `return_wild` to handle character concatenation and variable expansion.
static void	ride_quotes(char *buffer, char **swap, int *i)
{
	char	c;

	c = buffer[*i];
	if (c == 34)
	{
		*swap = ft_chrjoin(*swap, g_ms->buffer[i[0]++]);
		while (buffer[*i] != c)
		{
			if (ft_check_dolar_redir(g_ms->buffer, *i) == -1)
				return ;
			else if (ft_check_heredoc_no_sust(g_ms->buffer, i, swap))
				continue ;
			else if (buffer[*i] == '$')
				*swap = ft_strjoin_onefree(*swap, return_wild(buffer, i));
			else
				*swap = ft_chrjoin(*swap, g_ms->buffer[i[0]++]);
		}
		*swap = ft_chrjoin(*swap, g_ms->buffer[i[0]++]);
	}
	else if (c == 39)
	{
		*swap = ft_chrjoin(*swap, g_ms->buffer[i[0]++]);
		while (buffer[*i] != c)
			*swap = ft_chrjoin(*swap, g_ms->buffer[i[0]++]);
		*swap = ft_chrjoin(*swap, g_ms->buffer[i[0]++]);
	}
}

/// @brief Update the command buffer by expanding and handling 
/// dollar-sign variables.
/// This function is responsible for processing a command buffer and expanding
/// any dollar-sign variables it contains.
/// It iterates through the buffer, identifying dollar-signs ('$') and
/// replacing them with the appropriate values.
/// Single and double-quoted sections are preserved,
/// and other characters are copied as-is.
/// The updated buffer is then printed with a '#' suffix.
/// If an error occurs during processing (e.g., unbalanced quotes),
/// an error message is printed.
/// @note The function relies on other helper functions, such as `check_quotes`,
/// `ride_quotes`, and `return_wild`, to handle quoting and variable expansion.
/// @note The original buffer is freed,
/// and the updated buffer is assigned to `g_ms->buffer`.
void	change_dollars_buffer(void)
{
	char	*swap;
	int		i;

	i = 0;
	if (check_quotes(g_ms->buffer) == -1)
		print_error(NULL, 10);
	swap = (char *)ft_calloc(sizeof(char), 2);
	while (g_ms->buffer[i] && g_ms->signals->status_code == 0)
	{
		if (g_ms->buffer[i] == 39 || g_ms->buffer[i] == 34)
			ride_quotes(g_ms->buffer, &swap, &i);
		else
		{
			if (ft_check_dolar_redir(g_ms->buffer, i) == -1)
				return ;
			else if (ft_check_heredoc_no_sust(g_ms->buffer, &i, &swap))
				continue ;
			else if (g_ms->buffer[i] == '$')
				swap = ft_strjoin_onefree(swap, return_wild(g_ms->buffer, &i));
			else
				swap = ft_chrjoin(swap, g_ms->buffer[i++]);
		}
	}
	if (g_ms->signals->status_code != 0)
		return ;
	printf("%s#\n", swap);
	free (g_ms->buffer);
	g_ms->buffer = swap;
}
