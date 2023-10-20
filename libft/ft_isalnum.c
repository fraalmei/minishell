/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:23:27 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/20 12:51:29 by fraalmei         ###   ########.fr       */
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

	// check if the char is numeric
int	ft_isnum(int c)
{
	if (c <= 57 && c >= 48)
		return (1);
	return (0);
}

int	ft_is_str_num(char *str)
{
	if (!str)
		return (1);
	while (str)
	{
		if (!ft_isnum(*str))
			return (1);
		str++;
	}
	return (0);
}
