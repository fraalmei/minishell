/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:22:19 by fraalmei          #+#    #+#             */
/*   Updated: 2022/08/10 13:33:01 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// check if the char is alphabetic
int	ft_isalpha(int c)
{
	if (c <= 90 && c >= 65)
		return (1);
	else if (c <= 122 && c >= 97)
		return (1);
	return (0);
}
