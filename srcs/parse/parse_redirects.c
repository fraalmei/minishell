/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:01:31 by fraalmei          #+#    #+#             */
/*   Updated: 2023/09/02 12:31:11 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// TODO ESTO GENERA LEAKS XD

static char	**redir_join(char *buffer, int *i, char **redir)
{
	redir = str_strjoin_freeall(redir, ft_strndup (&buffer[*i], is_redir(&buffer[*i])));
	print_str_str(redir);
	*i += is_redir(&buffer[*i]);
	while (buffer[*i] == ' ')
		*i += 1;
	redir = str_strjoin_freeall(redir, read_word(buffer, i));
	*i += 1;
	while (buffer[*i] && is_redirecction(&buffer[*i]) == 0)
		*i += 1;
	*i -= 1;
	return (redir);
}

int	get_redir(char *buffer, int *i, t_prompt *swap)
{
	if (check_end_prom(&buffer[*i]) != 0)
		return (0);
	if (buffer[*i] == '<' && buffer[*i] != '<') // input redirect
		swap->input_redirect = redir_join(buffer, i, swap->input_redirect);
	else if (buffer[*i] == '<' && buffer[*i] == '<') // heredoc
		swap->here_doc = redir_join(buffer, i, swap->here_doc);
	else if (buffer[*i] == '>' && buffer[*i] != '>') // output rerdirect
		swap->output_redirect = redir_join(buffer, i, swap->output_redirect);
	else if (buffer[*i] == '>' && buffer[*i] == '>') // append redirect
		swap->append_redirect = redir_join(buffer, i, swap->append_redirect);
	return (0);
}
