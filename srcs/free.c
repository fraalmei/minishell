/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:02:58 by fraalmei          #+#    #+#             */
/*   Updated: 2023/05/21 11:04:30 by fraalmei         ###   ########.fr       */
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
			free (prom->arguments);
		if ((prom->options))
			free (prom->options);
		free (prom);
		prom = prom->next;
	}
	return (0);
}

int	free_env(t_env *env)
{
	t_env_var	*swap;

	if (env)
	{
		free_str (env->env);
		while (env->frst)
		{
			swap = env->frst;
			free (swap->name);
			free (swap->value);
			env->frst = swap->next;
			free (swap);
		}
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
	if (!g_mishell->buffer)
		free (g_mishell->buffer);
	free_env (g_mishell->envirorment);
	if (!g_mishell->prompt)
		free (g_mishell->prompt);
	free_signals(g_mishell->signals);
	return (0);
}
