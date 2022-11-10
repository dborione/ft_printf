/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:05:13 by dborione          #+#    #+#             */
/*   Updated: 2022/11/10 10:13:27 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(int nbr, char *base, int i)
{
	int	base_nbr;

	base_nbr = ft_strlen(base);
	if (nbr == INT_MIN)
		return (write(1, "-2147483648", 11));
	if (nbr < 0)
	{
		ft_putchar_int('-');
		nbr = -nbr;
		i = ft_putnbr_base(nbr, base, i + 1);
	}
	else
	{
		if (nbr >= base_nbr)
			i = ft_putnbr_base(nbr / base_nbr, base, i + 1);
		ft_putchar_int(base[nbr % base_nbr]);
	}
	return (i);
}

int	ft_u_putnbr_base(unsigned long nbr, char *base, int i)
{
	unsigned long	base_nbr;

	base_nbr = ft_strlen(base);
	if (nbr >= base_nbr)
		i = ft_u_putnbr_base(nbr / base_nbr, base, i + 1);
	ft_putchar_int(base[nbr % base_nbr]);
	return (i);
}
