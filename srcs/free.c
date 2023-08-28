/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:02:58 by fraalmei          #+#    #+#             */
/*   Updated: 2023/08/28 11:27:08 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// free the t_promt struct (or structs) generated from the buffer
int	free_prompt(t_prompt *prom)
{
	while (prom)
	{
		if ((prom->command))
			free (prom->command);
		if ((prom->arguments))
			free_str (prom->arguments);
		if ((prom->sep1))
			free(prom->sep1);
		free (prom);
		prom = prom->next;
	}
	return (0);
}

int	free_env_var(t_env_var *list)
{
	t_env_var	*swap;

	while (list)
	{
		swap = list;
		free (swap->name);
		free (swap->value);
		list = swap->next;
		free (swap);
	}
	return (0);
}

int	free_env(t_env *env)
{
	if (env)
	{
		free_str (env->env);
		free_env_var (env->frst);
		if (env->dir)
			free_env_var (env->dir);
		free (env);
	}
	return (0);
}

int	free_signals(t_sig *sig)
{
	free (sig);
	return (0);
}

int	free_global(void)
{
	if (!g_ms->buffer)
		free (g_ms->buffer);
	free_env (g_ms->envirorment);
	if (!g_ms->prompt)
		free (g_ms->prompt);
	free_signals(g_ms->signals);
	return (0);
}
