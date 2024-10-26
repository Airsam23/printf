/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshamdin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:05:11 by sshamdin          #+#    #+#             */
/*   Updated: 2023/02/07 18:05:14 by sshamdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	find_specifier(char spec, va_list args);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_putposnbr(unsigned int nb);
int	ft_puthex(unsigned int nb, int flag);
int	ft_putpointer(unsigned long long nb, int flag);
int	ft_add0x_putpointer(unsigned long long nb, int flag);

#endif
