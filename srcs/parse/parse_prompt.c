/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:40:44 by fraalmei          #+#    #+#             */
/*   Updated: 2023/11/16 13:19:35 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/// @brief Add the last prompt to the linked list of prompts.
/// This function appends the provided `swap` prompt to the end
/// of the linked list of prompts represented by the `prom` parameter.
/// It also calculates the number of arguments in the prompt.
/// @param prom A pointer to a pointer to the linked list of prompts.
/// @param swap The prompt to be added to the end of the list.
static void	add_last_prompt(t_prompt **prom, t_prompt *swap)
{
	if (swap->arguments)
		swap->n_arguments = ft_str_strlen(swap->arguments);
	else
		swap->n_arguments = 0;
	if (!*prom)
		*prom = swap;
	else
	{
		swap->arguments[swap->n_arguments] = NULL;
		last_prom(*prom)->next = swap;
		swap->prev = last_prom(*prom);
	}
	g_ms->n_prompts = num_prom(*prom);
}

/// @brief Add a prompt to the linked list of prompts based on pipe symbols.
/// This function adds a prompt to the linked list of prompts
/// based on the presence of pipe symbols ('|') in the command buffer.
/// It handles the creation and connection of prompts.
/// @param buff The command buffer.
/// @param prom A pointer to a pointer to the linked list of prompts.
/// @param swap The prompt to be added.
/// @param i A pointer to the iterator position in the command buffer.
/// @return The updated prompt pointer.
static t_prompt	*add_prom(char *buff, t_prompt **prom, t_prompt *swap, int *i)
{
	if (!*prom && is_pipe(&buff[*i]) > 0)
	{
		swap->sep1 = ft_chr_n_join(swap->sep1, \
			&buff[*i], is_pipe(&buff[*i]));
		*i += is_pipe(&buff[*i]);
		swap->n_arguments = ft_str_strlen(swap->arguments);
		*prom = swap;
		swap = NULL;
	}
	else if (is_pipe(&buff[*i]) > 0)
	{
		swap->sep1 = ft_chr_n_join(swap->sep1, \
			&buff[*i], is_pipe(&buff[*i]));
		*i += is_pipe(&buff[*i]);
		swap->n_arguments = ft_str_strlen(swap->arguments) - 1;
		last_prom(*prom)->next = swap;
		swap->prev = last_prom(*prom);
	}
	swap = new_prompt_struct();
	swap->sep0 = last_prom(*prom)->sep1;
	swap->pos_p += last_prom(*prom)->pos_p;
	return (swap);
}

/// @brief Process the command buffer to extract prompts and their contents.
/// This function processes the command buffer,
/// extracts prompts, and their contents (commands,
/// arguments, options, and redirections),
/// and populates the linked list of prompts.
/// @param buff The command buffer.
/// @param prom A pointer to a pointer to the linked list of prompts.
/// @param swap A pointer to the current prompt being processed.
/// @param i A pointer to the iterator position in the command buffer.
/// @return 0 on success, -1 on error.
static int	ride_buffer(char *buff, t_prompt **prom, t_prompt **swap, int *i)
{
	ignore_no_p(buff, i);
	if (check_start_prom(&buff[0], *prom) > 0)
		return (free_prompt(*prom), free_prompt (*swap), \
			print_error(2, ft_strndup(&buff[*i], is_pipe(&buff[*i])), 2), -1);
	if (!(*swap)->command && buff[*i] != ' ' && is_redirecction(&buff[*i]) == 0)
	{
		(*swap)->command = read_word(buff, i);
		(*swap)->arguments[0] = ft_strdup((*swap)->command);
		if ((*swap)->command == NULL)
			return (free (*prom), -1);
	}
	else if (buff[*i] && is_redirecction(&buff[*i]) == 0)
		get_option_args(buff, i, *swap);
	else if (buff[*i] && is_redir(&buff[*i]) != 0)
		get_redir(buff, i, *swap);
	else if (buff[*i] && is_pipe(&buff[*i]) != 0)
		*swap = add_prom(buff, prom, *swap, i);
	else if (check_end_prom(&buff[*i]) != 0)
		return (free_prompt(*prom), free_prompt (*swap), \
			print_error(258, ft_strdup("newline"), 258), -1);
	ignore_no_p(buff, i);
	return (0);
}

/// @brief Convert a command buffer to a linked list of prompts.
/// This function converts a command buffer into a linked list of prompts,
/// where each prompt represents a portion of the command buffer with commands,
/// arguments, options, and redirections.
/// @param buffer The command buffer to be processed.
/// @param prom The initial linked list of prompts (can be NULL).
/// @return A pointer to the linked list of prompts or NULL on error.
t_prompt	*buffer_to_prompt(char *buffer, t_prompt *prom)
{
	t_prompt	*swap;
	int			i;

	i = 0;
	signals_on(1);
	swap = new_prompt_struct();
	if (!swap)
		return (NULL);
	while (buffer[i])
	{
		if (ride_buffer(buffer, &prom, &swap, &i))
			return (NULL);
		if (g_ms->signals->status_code != 0)
			return (free_prompt(prom), free_prompt(swap), NULL);
	}
	add_last_prompt(&prom, swap);
	return (prom);
}
