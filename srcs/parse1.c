/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:29:45 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/15 09:43:09 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* static int	count_char(char *buffer, char c)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (buffer[++i])
		if (buffer[i] == c)
			count++;
	return (0);
} */

char	*read_word(char *string)
{
	int		i;
	char	*word;
	char	c;
	int		j;

	i = 0;
	while (string[i] && string[i] == ' ')
	{
		if (string[i] == 39 || string[i] == 34)
		{
			j = 0;
			c = string[i];
			while (string[i] != c)
				i++;
		}
		i++;
	}
	word = ft_substr(string, 0, i);
	return (word);
}


char	**d_str_join(char **str, char *new)
{
	void	**s;
	int		i;

	if (!str)
		str = (char **)ft_calloc(1, sizeof(char *));
	if (str == NULL || new == NULL)
		return (NULL);
	s = ft_calloc(sizeof(char *), ft_strlen_array((void *)str) + 2);
	i = -1;
	while (str[++i])
		s[i] = str[i];
	str[i] = new;
	return ((char **) s);
}

void	soft_split(char *buffer)
{
	char	**swap;
	char	*word;
	int		i;

	i = -1;
	printf("%s\n", buffer);
	while (buffer[++i])
	{
		word = read_word(buffer);
		swap = d_str_join(swap, word);
	}
	i = -1;
	printf("pasa\n");
	while (swap[++i])
		printf("%s\n", swap[i]);
	free_str(swap);
	printf("pasa\n");
}

/* 
static char	**add_split(char *buffer, char **split, char c)
{
	int		*count;
	int		i;
	int		l;
	char	**swap;

	i = 0;
	while (split[i])
		i++;
	count = ft_str_all_chr(buffer, c);
	swap = ft_calloc(sizeof(char *), i + 2);
	l = i + 1;
	while (l-- > 0)
		swap[l] = split[l];
	free (split);
	swap[i] = ft_substr(buffer, 0, count[0]);
	i++;
	swap[i] = ft_substr(buffer, count[1], count[2]);
	free (count);
	return (swap);
}

static void	print_splt(char **string)
{
	int		i;

	i = -1;
	while (string[++i])
		printf("%s\n", string[i]);
}

char	**splitter(char *buffer)
{
	int		i;
	int		j;
	char	**swap;
	char	**string;

	i = 0;
	j = 0;
	string = ft_calloc(sizeof(char *), 1);
	while (buffer[i])
	{
		if (buffer[i] == 39 || buffer[i] == 34)
		{
			if ((count_char(buffer, buffer[i]) % 2) == 0)
			{
				printf("Open %s.\n", &buffer[j]);
				string = add_split(&buffer[j], string, buffer[i]);
				j = i + 1;
			}
			else
				return (printf("Open quotes.\n"), NULL);
		}
		i++;
	}
	if (j + 1 == i)
	{
		swap = ft_calloc(sizeof(char *), ft_strlen_array((void *)string) + 1);
		i = 0;
		while (string[i])
			swap[i] = string[i];
		swap[i] = ft_strdup(&buffer[j]);
		free (string);
		print_splt(swap);
		return (swap);
	}
	else
	{
		print_splt(string);
		return (string);
	}
}
 */