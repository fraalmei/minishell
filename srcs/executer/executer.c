/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:45:48 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/19 17:15:24 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <executer.h>

void	ft_redir(void)
{
	t_prompt	*aux;

	aux = g_ms->prompt;
	while (aux)
	{
		if (aux->input_redirect)
			ft_inredir(aux);
		if (aux->output_redirect)
			ft_outredir(aux);
		aux = aux->next;
	}
}

void	launch_from_child(t_prompt *prompt)
{
	g_ms->sh_pid = fork();
	if (g_ms->sh_pid == 0)
		call_execve(prompt);
	else
	{
		close_all_fds(prompt);
		prompt->node_pid = g_ms->sh_pid;
		wait_childs();
	}
}

void	launch_single_process(t_prompt *prompt)
{
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
	ft_heredoc();
	ft_redir();
	g_ms->n_prompts = ft_lstpromptsize(g_ms->prompt);
	if (g_ms->n_prompts == 1)
		launch_single_process(g_ms->prompt);
	else
		launch_pipe_process(g_ms->prompt, g_ms->n_prompts + 1);
	g_ms->sh_pid = 0;
}
