/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:18:16 by fraalmei          #+#    #+#             */
/*   Updated: 2023/04/12 17:24:39 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// function to obtain the Current Working Directory
	// char *getcwdd (char *buf, size_t size);
int	get_wd(void)
{
	char	*buffer;

	buffer = (char *)ft_calloc(sizeof(char *), 1024);
	if (!buffer)
		return (-1);
	ft_printf("%s\n", getcwd(buffer, 1024));
	free (buffer);
	return (1);
}

int	actions(char *buffer, char **env)
{
	if (ft_strnstr(buffer, "exit", 4))
	{
		free(buffer);
		exit(0);
	}
	if (ft_strnstr(buffer, "pwd", 3))
		get_wd();
	else
		exec(buffer, env);
	return (0);
}
