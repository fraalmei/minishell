/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:33:07 by fraalmei          #+#    #+#             */
/*   Updated: 2023/06/07 15:27:30 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putstr(char *s)
{
	int		len;

	len = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s)
		len += write(1, &*s++, 1);
	return (len);
}

static int	ft_putnbr(long long int nbr, long long int i, char *base)
{
	int		len;

	len = 0;
	if (nbr < 0)
	{
		len += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= i)
		len += ft_putnbr(nbr / i, i, base);
	len += write(1, &base[nbr % i], 1);
	return (len);
}

	// it's a modified putnbr to print the start of a "pointer"
static int	ft_putptr(uintptr_t nbr, unsigned int i, char *base)
{
	int		len;

	len = 0;
	if (nbr >= i)
		len += ft_putnbr(nbr / i, i, base);
	len += write(1, &base[nbr % i], 1);
	return (len);
}

	// the function to check de variable and act consequently
static int	ft_selector(char str, va_list args)
{
	int		len;
	char	c;

	len = 0;
	if (str == 'c')
	{
		c = va_arg(args, int);
		len += write(1, &c, 1);
	}
	else if (str == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (str == 'p')
		len += ft_putstr("0x")
			+ ft_putptr(va_arg(args, uintptr_t), 16, "0123456789abcdef");
	else if (str == 'd' || str == 'i')
		len += ft_putnbr(va_arg(args, int), 10, "0123456789");
	else if (str == 'u')
		len += ft_putnbr(va_arg(args, unsigned int), 10, "0123456789");
	else if (str == 'x')
		len += ft_putnbr(va_arg(args, unsigned int), 16, "0123456789abcdef");
	else if (str == 'X')
		len += ft_putnbr(va_arg(args, unsigned int), 16, "0123456789ABCDEF");
	else if (str == '%')
		len += write(1, "%", 1);
	return (len);
}

	// to start printf create a len to count the printed chars
	// and start the list of variadic arguments
int	ft_printf(char const *str, ...)
{
	int		len;
	va_list	args;

	va_start(args, str);
	len = 0;
	while (*str)
	{
		if (*str != '%')
			len += write(1, str++, 1);
		else
		{
			str++;
			if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd'
				|| *str == 'i' || *str == 'u' || *str == 'x'
				|| *str == 'X' || *str == '%')
				len += ft_selector(*str, args);
			else if (*str != '\0')
				len += write(1, str, 1);
			else
				break ;
			str++;
		}
	}
	va_end(args);
	return (len);
}
