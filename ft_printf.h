/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:04:46 by dborione          #+#    #+#             */
/*   Updated: 2022/11/08 11:22:41 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

# define DEC "0123456789"
# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

size_t	ft_strlen(const char *str);
int		ft_putchar_int(char c);
int		ft_putstr_int(char *s);
int		ft_putnbr_base(int nbr, char *base, int i);
int		ft_u_putnbr_base(unsigned long nbr, char *base, int i);
int		ft_printf(const char *format, ...);

#endif
