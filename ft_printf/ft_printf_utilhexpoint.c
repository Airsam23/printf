/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilhexpoint.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshamdin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:17:27 by sshamdin          #+#    #+#             */
/*   Updated: 2023/02/08 16:19:27 by sshamdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nb, int flag)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (flag == 1)
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		count += ft_puthex(nb / 16, flag);
		count += ft_putchar(base[nb % 16]);
	}
	else
	{
		count += ft_putchar(base[nb % 16]);
	}
	return (count);
}

int	ft_putpointer(unsigned long long nb, int flag)
{
	int			count;
	char		*base;

	count = 0;
	base = "0123456789abcdef";
	if (flag == 1)
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		count += ft_putpointer(nb / 16, flag);
		count += ft_putchar(base[nb % 16]);
	}
	else
	{
		count += ft_putchar(base[nb % 16]);
	}
	return (count);
}

int	ft_add0x_putpointer(unsigned long long nb, int flag)
{
	int	count;

	count = 0;
	if (!nb)
		count += ft_putstr("(nil)");
	if (nb)
	{
		count += ft_putstr("0x");
		count += ft_putpointer(nb, flag);
	}
	return (count);
}
