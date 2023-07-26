/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:23:41 by fraalmei          #+#    #+#             */
/*   Updated: 2023/07/25 13:06:37 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_value(t_env *env, char	*var)
{
	t_env_var	*swap;

	if (!env)
		return (NULL);
	swap = env->frst;
	while (swap->name != var)
		swap = swap->next;
	return (swap->value);
}
