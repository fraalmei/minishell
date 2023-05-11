/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:33:01 by fraalmei          #+#    #+#             */
/*   Updated: 2022/08/11 09:16:12 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// the buffer can't be buff[10000000](aprox, can be diferent in any machine)
	// because the stack size is 8MB

	// read BUFFER_SIZE char of fd and return when it find a line break
	// it repeat if needed
static char	*gnl_read(int fd, char **mem)
{
	int		br;
	char	buf[BUFFER_SIZE + 1];

	br = 1;
	while (br > 0 && ft_strchr_nbr(*mem, '\n') == -1)
	{
		br = read(fd, buf, BUFFER_SIZE);
		if (br <= -1)
			return (free (*mem), NULL);
		buf[br] = '\0';
		*mem = ft_strjoin_onefree(*mem, buf);
	}
	return (*mem);
}

	// return the line inside of the returned string of gnl_read
	// and save a string with the chars left
static char	*get_line(char **mem)
{
	char	*line;
	int		i;
	char	*tmp;

	i = ft_strchr_nbr(*mem, '\n');
	if (i >= 0)
	{
		tmp = ft_strdup(*mem);
		line = ft_calloc(i, sizeof(char *));
		ft_memcpy(line, tmp, i);
		free (*mem);
		*mem = ft_strdup(&(tmp[i]));
		return (free (tmp), line);
	}
	else
	{
		if (*mem[0])
			line = *mem;
		else
			line = (free (*mem), NULL);
	}
	*mem = (NULL);
	return (line);
}

	//return a string in fd ended by a line break or eof
char	*get_next_line(int fd)
{
	static char		*memory[4096];

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (memory[fd] == NULL)
		memory[fd] = ft_calloc(1, 1);
	memory[fd] = gnl_read(fd, &memory[fd]);
	return (get_line(&memory[fd]));
}
