/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:08:29 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/21 20:33:39 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <executer.h>

void	ft_heredoc(void)
{
	int			i;
	t_prompt	*aux;

	aux = g_ms->prompt;
	while (aux)
	{
		i = -1;
		if (aux->input_redirect)
		{
			while (aux->input_redirect[++i])
			{
				if (aux->input_redirect[i][1] == '<')
				{
					aux->input_redirect[i] = ft_strtrim_frst_onefree(\
						aux->input_redirect[i], "<<");
					aux->input_redirect[i] = writeheredoc(\
						aux->input_redirect[i]);
				}
			}
		}
		aux = aux->next;
	}
}

char	*ft_expand_vars(char *line)
{
	int		i;
	char	*str;

	i = -1;
	str = ft_calloc(1, 1);
	while (line[++i])
	{
		if (line[i] == '$')
			str = ft_strjoin_onefree(str, return_wild(line, &i));
		else
			str = ft_chrjoin(str, line[i]);
	}
	return (free(line), str);
}

char	*writeheredoc(char *limiter)
{
	int		fd;
	char	*redir;
	char	*line;

	redir = ft_strjoin("./tmp/", limiter);
	fd = open(redir, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd < 0)
		return (NULL);
	line = readline("> ");
	while (line && ft_strncmp(line, limiter, ft_strlen(limiter)))
	{
		line = ft_expand_vars(line);
		ft_putstr_fd(line, fd);
		write(fd, "\n", 1);
		free(line);
		line = readline("> ");
	}
	(free(line), free(limiter));
	return (close(fd), redir);
}
