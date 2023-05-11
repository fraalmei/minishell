/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:59:14 by mgrau             #+#    #+#             */
/*   Updated: 2023/04/17 11:25:53 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*
** open_heredoc **
	if we have a heredoc we open it and assing our file in to it
Function Variables:
	herename location where our heredoc name is stored
	when herename is present,
	we open and assing it as our file in (node->file_in)
*/

void	open_heredoc(t_lst *node)
{
	char	*path;

	path = NULL;
	if (!node->herename)
		return ;
	else
	{
		path = ft_strjoin(TMP_PATH, node->herename);
		node->file_in = open(path, O_RDONLY);
		free(path);
	}
}

char	**str_ptr_dup(char **src)
{
	char	**dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (src[i])
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

/*
** ft_matrixlen **
finds out the lenght of a char ** matrix
*/

size_t	ft_matrixlen(char **matrix)
{
	size_t	len;

	len = 0;
	if (!matrix)
		return (0);
	while (matrix[len])
		len++;
	return (len);
}

/*
free(g_ms->instr->str_save) ?
*/

void	ft_execve_free(void)
{
	t_lst	*tmp;

	tmp = g_ms->instr;
	while (g_ms->instr != NULL)
	{
		tmp = g_ms->instr->next;
		free(g_ms->instr->str_cmd);
		free(g_ms->instr->str_line);
		free(g_ms->instr->str_aux);
		free(g_ms->instr->str_aux_save);
		free_matrix(g_ms->instr->str_args);
		free (g_ms->instr);
		g_ms->instr = tmp;
	}
	free (tmp);
	free(g_ms->prompt);
	free (g_ms->str);
	free(g_ms->pars_cmd);
	tmp = NULL;
}
