/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:08:29 by cagonzal          #+#    #+#             */
/*   Updated: 2023/09/08 12:54:45 by cagonzal         ###   ########.fr       */
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
					aux->input_redirect[i] = initheredoc(\
						aux->input_redirect[i]);
				}
			}
		}
		aux = aux->next;
	}
}

char	*initheredoc(char *limiter)
{
	limiter = writeheredoc(limiter);
	return (limiter);
}

char	*writeheredoc(char *limiter)
{
	int		fd;
	char	*redir;
	char	*line;

	redir = ft_strjoin("./tmp/", limiter);
	fd = open(redir, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	// Make Signals work
	if (fd < 0)
		return (NULL);
	line = readline("> ");
	while (ft_strncmp(line, limiter, ft_strlen(limiter)) != 0)
	{
		// Expanded Vars
		ft_putstr_fd(line, fd);
		write(fd, "\n", 1);
		line = (free(line), NULL);
		line = readline("> ");
	}
	line = (free(line), NULL);
	close(fd);
	return (redir);
}
