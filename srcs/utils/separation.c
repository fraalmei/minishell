/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:18:17 by fraalmei          #+#    #+#             */
/*   Updated: 2023/09/02 17:25:43 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/// @brief check the next 2 characters of the string to know
///			if its a redirecction
/// @param str the string to check
/// @return a int (0 if is not a redirecction, 1 if is 1 char
///			or 2 if is 2 chars)
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

/// @brief check the next 2 characters of the string to know if its a redirect
/// @param str the string to check
/// @return a int (0 if is not a redirecction,
/// 1 if is 1 char or 2 if is 2 chars)
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