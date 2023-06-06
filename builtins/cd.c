/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:40:06 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/06 12:37:50 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <dirent.h>

	// funcion cd
	// si existe el directorio se mueve a el
	// necesaria libreria dirent.h
	// genera leaks
int	cd(t_prompt *prompt)
{
	DIR	*dir;

	dir = opendir(prompt->arguments);
	if (dir == NULL)
		return (printf ("no such file or directory: %s\n", \
			prompt->arguments), ERROR);
	else
		return (chdir(prompt->arguments));
}
