/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:01:31 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/09 11:27:00 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	**redir_join_lite(char *swap, int *i, char **redir)
{
	redir = str_strjoin_freeall(redir, swap);
	*i -= 1;
	return (redir);
}

/// @brief 
///		line 33: if the redirect have 2 simbols add it to the string
/// @param buffer 
/// @param i 
/// @param redir 
/// @return 
static char	**redir_join(char *buffer, int *i, char **redir)
{
	char	*swap;

	swap = NULL;
	if (is_redir(&buffer[*i]) == 2)
		swap = ft_strjoin_allfree \
			(swap, ft_strndup(&buffer[*i], is_redir(&buffer[*i])));
	*i += is_redir(&buffer[*i]);
	ignore_no_p(buffer, i);
	if (buffer[*i] && is_redirecction(&buffer[*i]) != 0)
		return (print_error(ft_strndup(&buffer[*i], \
			is_redirecction(&buffer[*i])), 5), redir_join_lite(swap, i, redir));
	swap = ft_strjoin_allfree(swap, read_word(buffer, i));
	*i += 1;
	redir = str_strjoin_freeall(redir, swap);
	*i -= 1;
	return (redir);
}

/// @brief this function add to the prompt input_redirect or output_redirect
///			if the string have not a simbol means its a '>' or '<'
/// @param buffer 
/// @param i 
/// @param swap 
/// @return 
int	get_redir(char *buffer, int *i, t_prompt *swap)
{
	if (check_end_prom(&buffer[*i]) != 0)
		return (0);
	if (buffer[*i] == '<')
		swap->input_redirect = redir_join(buffer, i, swap->input_redirect);
	else if (buffer[*i] == '>')
		swap->output_redirect = redir_join(buffer, i, swap->output_redirect);
	ignore_no_p(buffer, i);
	if (!swap->command)
	{
		swap->command = read_word(buffer, i);
		if (swap->command)
			swap->arguments[0] = ft_strdup(swap->command);
	}
	while ((buffer[*i] == '-') && (buffer[*i + 1] != ' '))
	{
		if (check_opt_builtins(swap))
			return (1);
		swap->n_options = option_gen(swap, buffer, i);
		ignore_no_p(buffer, i);
	}
	return (0);
}
