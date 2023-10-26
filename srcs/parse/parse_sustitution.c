/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sustitution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:13:46 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/26 13:32:38 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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

static int	ft_counter_bar(char *buffer, int *i)
{
	if (buffer[*i] == 92)
	{
		if (buffer[*i + 1] == 34)
			i[0]++;
		else if (buffer[*i + 1] == 92)
			i[0]++;
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
	*swap = ft_chrjoin(*swap, g_ms->buffer[i[0]++]);
	if (c == 34)
	{
		while (buffer[*i] != c)
		{
			ft_counter_bar(g_ms->buffer, i);
			if (ft_check_dolar_redir(g_ms->buffer, *i) == -1)
				return ;
			else if (ft_check_heredoc_no_sust(g_ms->buffer, i, swap))
				continue ;
			else if (buffer[*i] == '$')
				*swap = ft_strjoin_onefree(*swap, return_wild(buffer, i));
			else
				*swap = ft_chrjoin(*swap, g_ms->buffer[i[0]++]);
		}
	}
	else if (c == 39)
		while (buffer[*i] != c)
			*swap = ft_chrjoin(*swap, g_ms->buffer[i[0]++]);
	*swap = ft_chrjoin(*swap, g_ms->buffer[i[0]++]);
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
			else if (g_ms->buffer[i] == '$' && g_ms->buffer[i + 1] != '?')
				swap = ft_strjoin_onefree(swap, return_wild(g_ms->buffer, &i));
			else if (g_ms->buffer[i] == '$' && g_ms->buffer[i + 1] == '?')
			{
				swap = ft_strjoin_allfree(swap, \
					ft_itoa(g_ms->signals->lst_stat_cod));
				i += 2;
			}
			else
				swap = ft_chrjoin(swap, g_ms->buffer[i++]);
		}
	}
	if (g_ms->signals->status_code != 0)
		return ;
	printf("%s#\n", swap);
	g_ms->buffer = (free (g_ms->buffer), swap);
}
