/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:09:09 by cagonzal          #+#    #+#             */
/*   Updated: 2023/02/17 14:38:25 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_makestr(char *str)
{
	int	len;

	if (!str)
		str = "(null)";
	len = 0;
	while (*str)
		len += write(1, str++, 1);
	return (len);
}

static int	ft_printnum(long long int num, int base, char *charbase)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		len += write(1, "-", 1);
		len += ft_printnum(-num, base, charbase);
	}
	else
	{
		if (num > (base - 1))
			len += ft_printnum(num / base, base, charbase);
		len += write(1, &charbase[num % base], 1);
	}
	return (len);
}

static int	ft_printpointer(uintptr_t num, unsigned int base, char *charbase)
{
	int	len;

	len = 0;
	len += ft_makestr("0x");
	if (num > (base - 1))
			len += ft_printnum(num / base, base, charbase);
	len += write(1, &charbase[num % base], 1);
	return (len);
}

static int	ft_printvble(char car, va_list list)
{
	int		len;
	char	p;

	len = 0;
	if (car == 'c')
	{
		p = va_arg(list, int);
		len += write(1, &p, 1);
	}
	else if (car == '%')
		len += write(1, "%", 1);
	else if (car == 's')
		len += ft_makestr(va_arg(list, char *));
	else if (car == 'i' || car == 'd')
		len += ft_printnum(va_arg(list, int), 10, "0123456789");
	else if (car == 'u')
		len += ft_printnum(va_arg(list, unsigned int), 10, "0123456789");
	else if (car == 'x')
		len += ft_printnum(va_arg(list, unsigned int), 16, "0123456789abcdef");
	else if (car == 'X')
		len += ft_printnum(va_arg(list, unsigned int), 16, "0123456789ABCDEF");
	else if (car == 'p')
		len += ft_printpointer(va_arg(list, uintptr_t), 16, "0123456789abcdef");
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list		list;
	int			len;

	va_start (list, str);
	len = 0;
	while (*str)
	{
		if (*str != '%')
			len += write(1, str, 1);
		else
		{
			str++;
			if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd'
				|| *str == 'i' || *str == 'u' || *str == 'x'
				|| *str == 'X' || *str == '%')
				len += ft_printvble(*str, list);
			else if (*str != '\0')
				len += write(1, str, 1);
		}
		if (*str != '\0')
			str++;
	}
	va_end (list);
	return (len);
}
