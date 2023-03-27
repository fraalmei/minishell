/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:58:43 by cagonzal          #+#    #+#             */
/*   Updated: 2023/02/17 14:38:25 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	**ft_freeptr(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (NULL);
}

static int	ft_nwords(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (cnt);
}

static char	*ft_nchars(char *word, char const *s, int k, int word_len)
{
	int		i;

	i = 0;
	while (word_len > 0)
	{
		word[i++] = s[k - word_len--];
	}
	return (word);
}

static char	**ft_split2(char **result, char const *s, char c, int word_num)
{
	int		i;
	int		k;
	int		word_len;

	i = 0;
	k = 0;
	word_len = 0;
	while (s[k] && i < word_num)
	{
		while (s[k] && s[k] == c)
			k++;
		while (s[k] && s[k] != c)
		{
			k++;
			word_len++;
		}
		result[i] = (char *)ft_calloc(sizeof(char), word_len + 1);
		if (!result)
			return (ft_freeptr(result));
		ft_nchars(result[i], s, k, word_len);
		word_len = 0;
		i++;
	}
	result[i] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		word_num;
	char	**result;

	if (s == 0)
		return (NULL);
	word_num = ft_nwords(s, c);
	result = (char **)malloc(sizeof(char *) * (word_num + 1));
	if (!result)
		return (NULL);
	ft_split2(result, s, c, word_num);
	return (result);
}
