/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:33:07 by fraalmei          #+#    #+#             */
/*   Updated: 2023/10/21 18:48:25 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef UINTPTR
# define UINTPTR unsigned long long int
#endif

#ifndef UNS_INT
# define UNS_INT unsigned int
#endif

static int	ft_putstr(char *s, int fd)
{
	int		len;

	len = 0;
	if (!s)
		return (ft_putstr("(null)", fd));
	while (*s)
		len += write(1, &*s++, fd);
	return (len);
}

static int	ft_putnbr(long long int nbr, long long int i, char *base, int fd)
{
	int		len;

	len = 0;
	if (nbr < 0)
	{
		len += write(1, "-", fd);
		nbr = -nbr;
	}
	if (nbr >= i)
		len += ft_putnbr(nbr / i, i, base, fd);
	len += write(1, &base[nbr % i], fd);
	return (len);
}

	// it's a modified putnbr to print the start of a "pointer"
static int	ft_putptr(uintptr_t nbr, unsigned int i, char *base, int fd)
{
	int		len;

	len = 0;
	if (nbr >= i)
		len += ft_putnbr(nbr / i, i, base, fd);
	len += write(1, &base[nbr % i], fd);
	return (len);
}

	// the function to check de variable and act consequently
static int	ft_selector(char str, va_list args, int fd)
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
		len += ft_putstr(va_arg(args, char *), fd);
	else if (str == 'p')
		len += ft_putstr("0x", fd)
			+ ft_putptr(va_arg(args, uintptr_t), 16, "0123456789abcdef", fd);
	else if (str == 'd' || str == 'i')
		len += ft_putnbr(va_arg(args, int), 10, "0123456789", fd);
	else if (str == 'u')
		len += ft_putnbr(va_arg(args, UNS_INT), 10, "0123456789", fd);
	else if (str == 'x')
		len += ft_putnbr(va_arg(args, UNS_INT), 16, "0123456789abcdef", fd);
	else if (str == 'X')
		len += ft_putnbr(va_arg(args, UNS_INT), 16, "0123456789ABCDEF", fd);
	else if (str == '%')
		len += write(1, "%", fd);
	return (len);
}

	// to start printf create a len to count the printed chars
	// and start the list of variadic arguments
int	ft_printf_fd(int fd, char const *str, ...)
{
	int		len;
	va_list	args;

	va_start(args, str);
	len = 0;
	while (*str)
	{
		if (*str != '%')
			len += write(1, str++, fd);
		else
		{
			str++;
			if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd'
				|| *str == 'i' || *str == 'u' || *str == 'x'
				|| *str == 'X' || *str == '%')
				len += ft_selector(*str, args, fd);
			else if (*str != '\0')
				len += write(1, str, fd);
			else
				break ;
			str++;
		}
	}
	va_end(args);
	return (len);
}
