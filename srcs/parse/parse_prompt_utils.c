/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prompt_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:36:49 by fraalmei          #+#    #+#             */
/*   Updated: 2023/09/14 13:05:07 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_prompt	*make_prompt_struct(void)
{
	t_prompt	*prom;

	prom = (t_prompt *)ft_calloc(sizeof(*prom), 2);
	if (!prom)
		return (NULL);
	prom->prev = NULL;
	prom->sep0 = NULL;
	prom->infile = STDIN;
	prom->outfile = STDOUT;
	prom->b_success = FALSE;
	prom->command = NULL;
	prom->n_options = 0;
	prom->n_arguments = 0;
	prom->arguments = NULL;
	prom->arguments = (char **)ft_calloc(sizeof(char *), 2);
	prom->input_redirect = NULL;
	prom->output_redirect = NULL;
	prom->sep1 = NULL;
	prom->next = NULL;
	return (prom);
}

/// @brief guess it
/// @param prom the first t_prompt of the list
/// @return a pointer to the last t_prompt
t_prompt	*last_prom(t_prompt *prom)
{
	t_prompt	*swap;

	swap = prom;
	while (swap->next)
		swap = swap->next;
	return (swap);
}
