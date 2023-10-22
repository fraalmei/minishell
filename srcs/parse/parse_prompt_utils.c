/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prompt_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:36:49 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/22 05:51:14 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_prompt	*new_prompt_struct(void)
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
	prom->arguments = (char **)ft_calloc(sizeof(char *), 3);
	prom->input_redirect = NULL;
	prom->output_redirect = NULL;
	prom->pos_p = 1;
	prom->sep1 = NULL;
	prom->next = NULL;
	return (prom);
}

void	ignore_no_p(char *buffer, int *i)
{
	while (buffer[*i] == ' ' || buffer[*i] == '\t')
		*i += 1;
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

int	num_prom(t_prompt *prom)
{
	int	i;

	i = 1;
	while (prom->next)
	{
		i++;
		prom = prom->next;
	}
	return (i);
}

int	check_end_prom(char *buffer)
{
	int		i;

	i = 0;
	if (is_redir(buffer) > 0)
	{
		i += is_redir(buffer);
		while (buffer[i] && buffer[i] == ' ')
			i++;
		if (!buffer[i])
			return (1);
	}
	return (0);
}
