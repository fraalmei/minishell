/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:01:31 by fraalmei          #+#    #+#             */
/*   Updated: 2023/09/07 10:31:35 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	**redir_join(char *buffer, int *i, char **redir)
{
	//redir = str_strjoin_freeall(redir, ft_strndup (&buffer[*i], is_redir(&buffer[*i])));
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
static char	**output_join(char *buffer, int *i, char **redir)
{
	char	*swap;

	swap = NULL;
	swap = ft_strjoin_allfree (swap, ft_strndup(&buffer[*i], is_redir(&buffer[*i])));
	*i += is_redir(&buffer[*i]);
	while (buffer[*i] == ' ')
		*i += 1;
	if (!buffer[*i] && is_redirecction(&buffer[*i]) != 0)
	{
		redir = str_strjoin_freeall(redir, swap);
		*i -= 1;
		return (redir);
	}
	swap = ft_strjoin_allfree(swap, read_word(buffer, i));
	*i += 1;
	while (buffer[*i] && is_redirecction(&buffer[*i]) == 0)
		*i += 1;
	redir = str_strjoin_freeall(redir, swap);
	*i -= 1;
	return (redir);
}

int	get_redir(char *buffer, int *i, t_prompt *swap)
{
	if (check_end_prom(&buffer[*i]) != 0)
		return (0);
	if (buffer[*i] == '<' && buffer[*i + 1] != '<')
		swap->input_redirect = redir_join(buffer, i, swap->input_redirect);
	else if (buffer[*i] == '<' && buffer[*i + 1] == '<')
		swap->here_doc = redir_join(buffer, i, swap->here_doc);
	else if (buffer[*i] == '>')
		swap->output_redirect = output_join(buffer, i, swap->output_redirect);
	return (0);
}
