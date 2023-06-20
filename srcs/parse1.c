/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   parse1.c	   :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: fraalmei <fraalmei@student.42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2023/04/15 12:29:45 by fraalmei	  #+#	#+#	 */
/*   Updated: 2023/06/15 14:18:36 by fraalmei	 ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include <minishell.h>

/// @brief creates and malloc an t_prompt structure and in itialize it
/// @param .no need parameters
/// @return a t_prompt structure
static t_prompt	*create_prompt_struct(void)
{
	t_prompt	*prom;

	prom = (t_prompt *)ft_calloc(sizeof(*prom), 1);
	if (!prom)
		return (NULL);
	prom->prev = NULL;
	prom->sep0 = NULL;
	prom->command = NULL;
	prom->n_options = -1;
	prom->options = NULL;
	prom->arguments = NULL;
	prom->sep1 = NULL;
	prom->next = NULL;
	return (prom);
}

/// @brief check the next 2 characters of the string to know if its a redirecction
/// @param str the string to check
/// @return a int (0 if is not a redirecction, 1 if is 1 char or 2 if is 2 chars)
static int	is_redirecction(char *str)
{
	if (!str)
		return (0);
	else if (str[0] == '|' && (!str[1] || str[1] != '|'))
		return (1);
	else if (str[0] == '|' && str[1] == '|')
		return (2);
	else if (str[0] == '<' && (!str[1] || str[1] != '<'))
		return (1);
	else if (str[0] == '<' && str[1] == '<')
		return (2);
	else if (str[0] == '>' && (!str[1] || str[1] != '>'))
		return (1);
	else if (str[0] == '>' && str[1] == '>')
		return (2);
	else if (str[0] == '&' && (!str[1] || str[1] != '&'))
		return (1);
	else if (str[0] == '&' && str[1] == '&')
		return (2);
	return (0);
}

/// @brief check the number of options in the string
/// @param s the string to check
/// @return a int with the numbers of options finded
int	n_options(char **s)
{
	int		i;
	int		l;
	int		count;
	char	*swap;

	i = 0;
	count = 0;
	while (s[i] && is_redirecction(s[i]) == 0)
	{
		swap = s[i];
		l = 1;
		if (ft_str_frst_cmp(&swap[0], "-") != 0)
			return (count);
		while (swap[l])
		{
			if (ft_isalnum(swap[l]))
				count++;
			else
				return (-1);
			l++;
		}
		if (ft_str_frst_cmp(&swap[0], "-") != 0)
			return (count);
		i++;
	}
	return (count);
}

/// @brief create an string with the options read in the param string
/// @param s the string to check
/// @param count the numbers of options must have the return string
/// @return a string with the options
char	*option_generator(char **s, int count, int *i)
{
	char	*options;
	int		l;
	char	*swap;
	int		x;

	l = 0;
	options = (char *)ft_calloc(sizeof(char), count + 1);
	if (!options)
		return (NULL);
	x = 0;
	while (s[*i] && is_redirecction(s[*i]) == 0)
	{
		swap = s[*i];
		if (ft_str_frst_cmp(&swap[0], "-") == 0)
		{
			l = 1;
			while (swap[l] && x < count)
				options[x++] = swap[l++];
			free (swap);
			*i += 1;
		}
		else
			break ;
	}
	return (options);
}

/// @brief create an structure t_prompt
/// @param s the string with all words
/// @return a pointer of a t_prompt structure
t_prompt	*buff_to_prom(char **s)
{
	int			i;
	int			token_limit;
	t_prompt	*prom;

	i = 0;
	prom = create_prompt_struct();
	token_limit = 1;
	if (is_redirecction(s[i]) != 0)
		prom->sep0 = s[i++];
	while (s[i] && is_redirecction(s[i]) == 0)
	{
		if (!prom->command)
		{
			prom->command = ft_strtrim_onefree(s[i], " \t\n\v\f\r");
			prom->n_options = n_options(&s[i + 1]);
			if (prom->n_options == -1)
				return (printf("illegal option\n"), NULL);
			prom->options = option_generator(&s[i + 1], prom->n_options, &i);
		}
		else
			prom->arguments = ft_strtrim_onefree(ft_strjoin_allfree(\
				ft_strjoin_onefree(prom->arguments, " "), s[i]), " \t\n\v\f\r");
		i++;
	}
	if (is_redirecction(s[i]) != 0)
		prom->sep1 = s[i];
	return (prom);
}

/// @brief guess it
/// @param prom the first t_prompt of the list
/// @return a pointer to the last t_prompt
t_prompt	*last_prom(t_prompt *prom)
{
	while (prom->next)
		prom = prom->next;
	return (prom);
}

/// @brief create a list of t_prompt
/// @param buffer the bouble string with all the words
/// @return the first struct t_prompt of the list
t_prompt	*buffer_to_prom(char **buffer)
{
	int			i;
	t_prompt	*prom;
	t_prompt	*swap;

	i = 0;
	prom = buff_to_prom(&buffer[i]);
	while (buffer[i] && is_redirecction(buffer[i]) == 0)
		i++;
	while (buffer[i])
	{
		swap = buff_to_prom(&buffer[i]);
		if (!swap)
			return (free_prompt(prom), NULL);
		i++;
		while (buffer[i] && is_redirecction(buffer[i]) == 0)
			i++;
		swap->prev = last_prom(prom);
		last_prom(prom)->next = swap;
	}
	free (buffer);
	return (prom);
}

/// @brief join a string to a double string 
/// mallocing a new double string and free the old
/// @param str the doubl string for join
/// @param char* the string to join
/// @return the new double string
char	**d_str_join(char **str, char *new)
{
	int		len;
	char	**s;
	int		i;

	len = 0;
	if (!new)
		return (str);
	if (str)
		while (str[len])
			len++;
	s = (char **)ft_calloc((len + 2), sizeof(char *));
	if (!s)
		return (NULL);
	i = -1;
	while (++i < len)
		s[i] = str[i];
	s[i] = new;
	s[i + 1] = NULL;
	free (str);
	return (s);
}

/// @brief read a create a string counting the quotes
/// @param string the string is the buffer got for the readline
/// @return a string between quotes or spaces
char	*read_word(char *string, int *i)
{
	char	*word;
	char	*swap;
	char	c;

	word = (char *)ft_calloc(sizeof(char), 1);
	while (string[*i] && string[*i] != ' ' && is_redirecction(&string[*i]) == 0)
	{
		if (string[*i] == 39 || string[*i] == 34)
		{
			word = ft_chrjoin(word, string[*i]);
			c = string[*i];
			*i += 1;
			while (string[*i] && string[*i] == '$')
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
	if (ft_strlen(word) == 0 && is_redirecction(&string[*i]) > 0)
	{
		word = ft_chr_n_join(word, &string[*i], is_redirecction(&string[*i]));
		*i += is_redirecction(&string[*i]);
	}
	return (word);
}

/* char	*get_in_meta(char *string, char *word, int *init, int i)
{
	char	*swap;

	word = ft_substr(string, *init, i - *init);
	*init = i;
	swap = return_wild(string, &*init);
	if (swap)
		word = ft_strjoin_onefree(word, swap);
	return (word);
}

char	*read_word(char *string, int *init)
{
	char	*word;
	int		i;

	i = *init;
	word = (char *)ft_calloc(sizeof(char), 1);
	while (string[i] && string[i] != ' ' && is_redirecction(&string[i]) == 0)
	{
		if (string[i] == '$')
			word = get_in_meta(string, word, &*init, i);
		else if (string[i] == 39)
			i += ft_frst_chrcmp(&string[i + 1], 39);
		else if (string[i] == 34)
		{
			while (string[i] && string[i] != 34)
			{
				if (string[i] == '$')
					word = get_in_meta(string, word, &*init, i);
				else
					i++;
			}
			i++;
		}
		else
			i++;
	}
	word = ft_strjoin_allfree(word, ft_substr(string, *init, i - *init));
	printf ("devuelve %i - %i - %s\n", *init, i, word);
	*init += i;
	return (word);
} */


/// @brief divide the buffer into strings
/// @param buffer the buffer got from the readline
/// @return aa double string with all words from the buffer
char	**soft_split(char *buffer)
{
	char	**swap;
	char	*word;
	int		i;

	i = 0;
	swap = NULL;
	while (buffer[i])
	{
		if (buffer[i] == ' ')
			i++;
		else
		{
			word = read_word(buffer, &i);
			if (word)
				swap = d_str_join(swap, word);
		}
	}
	return (swap);
}

// veamos | que se| puede |hacer por aq|ui
