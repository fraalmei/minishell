/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:27:26 by fraalmei          #+#    #+#             */
/*   Updated: 2023/05/10 12:15:22 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	free_str(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free (s[i++]);
	free (s);
	return (0);
}

int	free_str_str(char ***s)
{
	int		i;

	i = 0;
	while (s[i])
		free_str (s[i++]);
	free (s);
	return (0);
}
