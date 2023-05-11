/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:23:27 by fraalmei          #+#    #+#             */
/*   Updated: 2022/08/10 13:32:29 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// check if the char is alphanumeric
int	ft_isalnum(int c)
{
	if (c <= 57 && c >= 48)
		return (1);
	else if (c <= 90 && c >= 65)
		return (1);
	else if (c <= 122 && c >= 97)
		return (1);
	return (0);
}
