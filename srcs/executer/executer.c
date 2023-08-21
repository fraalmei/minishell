/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:45:48 by cagonzal          #+#    #+#             */
/*   Updated: 2023/08/17 16:57:39 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <executer.h>

void	open_heredoc(t_prompt prompt)
{
	char		*path;
	int			heredoc;
	t_prompt	tmp;

	path = NULL;
	tmp = prompt;
	while (tmp)
	{
		if (ft_strcmp(prompt->command, "<<"))
			initheredoc(tmp);
		tmp = tmp->next;
	}
	else
	{
		path = ft_strjoin(TMP_PATH, prompt->herename);
		prompt->file_in = open(path, O_RDONLY);
		free(path);
	}
}

void	launch_single_process(t_prompt **prompt)
{
	// open_heredoc(prompt);
	if (prompt->command)
	{
		if (is_builtin(prompt->command))
			launch_from_father(prompt);
		else
			launch_from_child(prompt);
	}
}

void	start_executer(void)
{
	g_ms->n_prompts = ft_lstpromptsize(g_ms->prompt);
	if (g_ms->n_prompts == 1)
		launch_single_process(g_ms->prompt);
	// else
	// {
	// 	launch_mult_process(g_ms->prompt);
	// 	wait_childs();
	// }
}
