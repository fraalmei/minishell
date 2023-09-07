/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:45:48 by cagonzal          #+#    #+#             */
/*   Updated: 2023/09/07 15:13:35 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <executer.h>

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
	int	i;

	if (prompt->input_redirect)
	{
		i = -1;
		while (prompt->input_redirect[++i])
			prompt->infile = openfile(prompt->input_redirect[i], INFILE);
	}
	if (prompt->output_redirect)
	{
		i = -1;
		while (prompt->output_redirect[++i])
		{
			if (prompt->output_redirect[i][1] != '>')
			{
				prompt->output_redirect[i] = ft_strtrim_frst_onefree(\
					prompt->output_redirect[i], ">");
				prompt->outfile = openfile(prompt->output_redirect[i] \
						, OUTFILE);
			}
			else
			{
				prompt->output_redirect[i] = ft_strtrim_frst_onefree(\
					prompt->output_redirect[i], ">>");
				prompt->outfile = openfile(prompt->output_redirect[i] \
						, APPFILE);
			}
		}
	}
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
	// 	launch_pipe_process(g_ms->prompt, g_ms->n_prompts);
	// 	wait_childs();
	// }
}
