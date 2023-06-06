/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:40:06 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/04 12:47:01 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <dirent.h>

int	cd(t_prompt *prompt)
{
	DIR	*dir;

	printf("entra\n");
	dir = opendir(prompt->arguments);
	if (dir == NULL)
		return (printf ("no such file or directory: %s\n", \
			prompt->arguments), ERROR);
	else
		return (chdir(prompt->arguments));
}
