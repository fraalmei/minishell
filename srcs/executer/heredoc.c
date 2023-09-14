/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:08:29 by cagonzal          #+#    #+#             */
/*   Updated: 2023/09/14 10:50:56 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <executer.h>


void	ft_heredoc(void)
{
	int			i;
	t_prompt	*aux;

	mkdir("./tmp/", S_IRWXU | S_IRWXG | S_IRWXO);
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
					system("leaks -q minishell");
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
	char	*value;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '$' && line[i + 1] == ' ')
		{
			str = ft_strjoin(str, return_wild(line, ft_str_frst_chr('$')));
			while (line[i] != ' ')
				i++;
		}
		else
			str = ft_chrjoin(line[i]);
	}
	return (line);
}

char	*writeheredoc(char *limiter)
{
	int		fd;
	char	*redir;
	char	*line;

	redir = ft_strjoin("./tmp/", limiter);
	fd = open(redir, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	signals_dont();
	if (fd < 0)
		return (NULL);
	line = readline("> ");
	while (line && ft_strncmp(line, limiter, ft_strlen(limiter)) != 0)
	{

		ft_putstr_fd(line, fd);
		write(fd, "\n", 1);
		free(line);
		line = readline("> ");
	}
	(free(line), free(limiter));
	return (close(fd), redir);
}
