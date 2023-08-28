/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prompt_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:36:49 by fraalmei          #+#    #+#             */
/*   Updated: 2023/08/28 11:35:02 by fraalmei         ###   ########.fr       */
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
	prom->command = NULL;
	prom->n_options = 0;
	prom->n_arguments = 0;
	prom->arguments = NULL;
	prom->sep1 = NULL;
	prom->next = NULL;
	return (prom);
}

/// @brief check the next 2 characters of the string to know if its a redirecction
/// @param str the string to check
/// @return a int (0 if is not a redirecction, 1 if is 1 char or 2 if is 2 chars)
int	is_redirecction(char *str)
{
	if (!str)
		return (-1);
	else if (is_pipe(str) > 0)
		return (is_pipe(str));
	else if (is_redir(str) > 0)
		return (is_redir(str));
	return (0);
}

/// @brief check the next 2 characters of the string to know if its a pipe
/// @param str the string to check
/// @return a int (0 if is not a pipe, 1 if is 1 char or 2 if is 2 chars)
int	is_pipe(char *str)
{
	if (!str)
		return (-1);
	else if (str[0] == '|' && (!str[1] || str[1] != '|'))
		return (1);
	else if (str[0] == '|' && str[1] == '|')
		return (2);
	else if (str[0] == '&' && (!str[1] || str[1] != '&'))
		return (1);
	else if (str[0] == '&' && str[1] == '&')
		return (2);
	return (0);
}

/// @brief check the next 2 characters of the string to know if its a redirecction
/// @param str the string to check
/// @return a int (0 if is not a redirecction, 1 if is 1 char or 2 if is 2 chars)
int	is_redir(char *str)
{
	if (!str)
		return (-1);
	if (str[0] == '<' && (!str[1] || str[1] != '<'))
		return (1);
	else if (str[0] == '<' && str[1] == '<')
		return (2);
	else if (str[0] == '>' && (!str[1] || str[1] != '>'))
		return (1);
	else if (str[0] == '>' && str[1] == '>')
		return (2);
	return (0);
}

int	check_quotes(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		if (str[i] == 39 || str[i] == 34)
		{
			c = str[i];
			i++;
			while (str[i] && c != str[i])
				i++;
			if (!str[i])
				return (-1);
		}
		i++;
	}
	return (0);
}

/// @brief guess it
/// @param prom the first t_prompt of the list
/// @return a pointer to the last t_prompt
t_prompt	*last_prom(t_prompt *prom)
{
	t_prompt	*swap;

	swap = prom;
	while (swap->next)
	{
		printf("veamos cuantas veces\n");
		swap = swap->next;
	}
	return (swap);
}
