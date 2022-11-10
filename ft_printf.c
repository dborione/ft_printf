/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:04:32 by dborione          #+#    #+#             */
/*   Updated: 2022/11/08 11:20:11 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_format(char format, va_list args)
{
	unsigned long	address;

	if (format == '%')
		return (ft_putchar_int(format));
	else if (format == 'c')
		return (ft_putchar_int(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr_int(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_base(va_arg(args, int), DEC, 1));
	else if (format == 'u')
		return (ft_u_putnbr_base(va_arg(args, unsigned int), DEC, 1));
	else if (format == 'p')
	{
		address = (unsigned long)va_arg(args, void *);
		return (ft_putstr_int("0x") + ft_u_putnbr_base(address, HEX_LOW, 1));
	}
	else if (format == 'x')
		return (ft_u_putnbr_base(va_arg(args, unsigned int), HEX_LOW, 1));
	else if (format == 'X')
		return (ft_u_putnbr_base(va_arg(args, unsigned int), HEX_UP, 1));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			i += ft_printf_format(*format, args);
		}
		else
		{
			ft_putchar_int(*format);
			i++;
		}
		format++;
	}
	va_end(args);
	return (i);
}
