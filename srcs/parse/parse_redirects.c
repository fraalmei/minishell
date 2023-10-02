/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:01:31 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/02 16:18:40 by fraalmei         ###   ########.fr       */
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
	printf("veamos %s\n", swap);
	if (buffer[*i] && is_redirecction(&buffer[*i]) != 0)
		return (print_error(ft_strndup(&buffer[*i], \
			is_redirecction(&buffer[*i])), 5), redir_join_lite(swap, i, redir));
	if (ft_strcmp(swap, "<<") != 0 && buffer[*i] != '$')
		swap = ft_strjoin_allfree(swap, read_word(buffer, i));
	else
		swap = ft_strjoin_allfree(swap, read_word(buffer, i));
	printf("veamos %s\n", swap);
	*i += 1;
	/* while (buffer[*i] && is_redirecction(&buffer[*i]) == 0)
		*i += 1; */
	redir = str_strjoin_freeall(redir, swap);
	//*i -= 1;
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
	//printf ("pasa1 %s\n", &buffer[*i]);
	ignore_no_p(buffer, i);
	//printf ("pasa2 %s\n", &buffer[*i]);
	while ((buffer[*i] == '-') && (buffer[*i + 1] != ' '))
	{
		printf ("entra\n");
		swap->n_options = option_gen(swap, buffer, i);
		ignore_no_p(buffer, i);
	}
	return (0);
}
