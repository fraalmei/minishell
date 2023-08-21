/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:40:44 by fraalmei          #+#    #+#             */
/*   Updated: 2023/08/07 13:37:01 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*read_word(char *string, int *i)
{
	char	*word;
	char	*swap;
	char	c;

	word = (char *)ft_calloc(sizeof(char), 2);
	while (string[*i] && string[*i] != ' ' && is_redirecction(&string[*i]) == 0)
	{
		if (string[*i] == 39 || string[*i] == 34)
		{
			c = string[*i];
			*i += 1;
			while (string[*i] && string[*i] != c)
			{
				if (string[*i] == '$' && c == 34)
				{
					swap = return_wild(string, &*i);
					*i += 1;
					if (swap)
						word = ft_strjoin_onefree(word, swap);
				}
				else
				{
					word = ft_chrjoin(word, string[*i]);
					*i += 1;
				}
			}
			*i += 1;
		}
		else
		{
			if (string[*i] == '$')
			{
				swap = return_wild(string, &*i);
				*i += 1;
				if (swap)
					word = ft_strjoin_onefree(word, swap);
			}
			else
			{
				word = ft_chrjoin(word, string[*i]);
				*i += 1;
			}
		}
	}
	*i -= 1;
	return (word);
}

int	option_gen(t_prompt *prom, char *str, int *i)
{
	int		l;
	int		x;

	if (!prom->options)
		prom->options = (char *)ft_calloc(sizeof(char), 2);
	if (!prom->options)
		return (-1);
	x = 0;
	l = ft_strlen(prom->options);
	while (str[*i] && is_redirecction(&str[*i]) == 0 && str[*i] != ' ')
	{
		if (str[*i] == '-' && x < 1)
			x++;
		else if (x > 1)
		{
			g_ms->signals->error_status = 1;
			return (printf("illegal option -- -\n"), -1);
		}
		else if (!ft_strrchr(prom->options, str[*i]))
			prom->options = (l++, ft_chrjoin(prom->options, str[*i]));
		*i += 1;
	}
	return (l);
}

t_prompt	*buffer_to_prompt(char *buffer)
{
	t_prompt	*prom;
	t_prompt	*swap;
	int			i;

	i = 0;
	if (check_quotes(buffer))
		return (printf("Comillas abiertas\n"), NULL);
	swap = make_prompt_struct();
	if (!swap)
		return (NULL);
	prom = NULL;
	while (buffer[i])
	{
		if (!swap->command && buffer[i] != ' ' && is_redirecction(&buffer[i]) == 0)
		{
			swap->command = read_word(buffer, &i);
			if (swap->command == NULL)
				return (free (prom), NULL);
		}
		else if (buffer[i] != ' ' && is_redirecction(&buffer[i]) == 0)
		{
			if ((buffer[i] == '-') && !swap->arguments)
				swap->n_options = option_gen(swap, buffer, &i);
			else if (!swap->arguments)
				swap->arguments = str_strjoin_freeall(swap->arguments, read_word(buffer, &i));
			else
				swap->arguments = str_strjoin_freeall(swap->arguments, read_word(buffer, &i));
		}
		else if (is_redirecction(&buffer[i]) != 0)
		{
			if (!swap->command)
				return (free(prom), write(1, "syntax error near unexpected token ", 36), write(1, &buffer[i], is_redirecction(&buffer[i])), write(1, "\n", 1), NULL);
			if (!prom)
			{
				swap->sep1 = ft_chr_n_join(swap->sep1, &buffer[i], is_redirecction(&buffer[i]));
				printf("%s\n", swap->sep1);
				i += is_redirecction(&buffer[i]) - 1;
				swap->n_arguments = ft_str_strlen(swap->arguments);
				prom = swap;
			}
			else
			{
				swap->sep1 = ft_chr_n_join(swap->sep1, &buffer[i], is_redirecction(&buffer[i]));
				printf("%s\n", swap->sep1);
				i += is_redirecction(&buffer[i]) - 1;
				swap->n_arguments = ft_str_strlen(swap->arguments);
				last_prom(prom)->next = swap;
				swap->prev = last_prom(prom);
			}
			printf("puede que pete aqui 5\n");
			swap = make_prompt_struct();
			swap->sep0 = last_prom(prom)->sep1;
		}
		i++;
	}
	if (!prom)
	{
		if (swap->arguments)
			swap->n_arguments = ft_str_strlen(swap->arguments);
		else
			swap->n_arguments = 0;
		prom = swap;
	}
	else
	{
		if (swap->arguments)
			swap->n_arguments = ft_str_strlen(swap->arguments);
		else
			swap->n_arguments = 0;
		last_prom(prom)->next = swap;
		swap->prev = last_prom(prom);
	}
	return (prom);
}
