/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:08:29 by cagonzal          #+#    #+#             */
/*   Updated: 2023/11/16 16:20:21 by fraalmei         ###   ########.fr       */
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

void	*w_hdoc_cycle(char *limiter, int fd)
{
	char	*buffer;

	buffer = readline("> ");
	while (buffer && ft_strcmp(buffer, limiter))
	{
		buffer = ft_expand_vars(buffer);
		(ft_putstr_fd(buffer, fd), write(fd, "\n", 1), free(buffer));
		buffer = readline("> ");
	}
	if (!buffer)
		exit(1);
	(free(buffer), free(limiter));
	exit(0);
}

char	*writeheredoc(char *limiter)
{
	int		status;
	int		fd;
	char	*redir;

	status = 0;
	redir = ft_strjoin("./tmp/", limiter);
	fd = open(redir, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd < 0)
		return (NULL);
	g_ms->sh_pid = fork();
	if (g_ms->sh_pid == 0)
		w_hdoc_cycle(limiter, fd);
	else
		(signals_on(2), waitpid(g_ms->sh_pid, &status, 0));
	if (status != 0)
		g_ms->signals->hdoc_cod = 2;
	return (close(fd), redir);
}
