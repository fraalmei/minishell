/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:40:03 by fraalmei          #+#    #+#             */
/*   Updated: 2023/05/21 12:38:10 by fraalmei         ###   ########.fr       */
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
	return (0);
}
