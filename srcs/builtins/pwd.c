/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:40:03 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/21 22:27:28 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

	// function to obtain the Current Working Directory
	// char *getcwd (char *buf, size_t size);
int	get_wd(void)
{
	char	*buffer;

	buffer = (char *)ft_calloc(sizeof(char *), 1024);
	if (!buffer)
		return (-1);
	getcwd(buffer, 1024);
	if (!buffer)
		ft_printf("%s\n", get_value(g_ms->envirorment->frst, "PWD"));
	else
		ft_printf("%s\n", buffer);
	free (buffer);
	return (0);
}

	// function to obtain the Current Working Directory
	// char *getcwd (char *buf, size_t size);
char	*get_wd_char(void)
{
	char	*buffer;

	buffer = (char *)ft_calloc(sizeof(char *), 1024);
	if (!buffer)
		return (NULL);
	getcwd(buffer, 1024);
	if (!buffer)
		return (get_value(g_ms->envirorment->frst, "PWD"));
	return (buffer);
}
