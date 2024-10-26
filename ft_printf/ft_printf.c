/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshamdin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:03:32 by sshamdin          #+#    #+#             */
/*   Updated: 2023/02/07 18:03:57 by sshamdin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_specifier(char spec, va_list args)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += ft_putchar(va_arg(args, int));
	if (spec == 's')
		count += ft_putstr(va_arg(args, char *));
	if (spec == 'i' || spec == 'd')
		count += ft_putnbr(va_arg(args, int));
	if (spec == '%')
		count += ft_putchar('%');
	if (spec == 'u')
		count += ft_putposnbr(va_arg(args, unsigned int));
	if (spec == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 0);
	if (spec == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 1);
	if (spec == 'p')
		count += ft_add0x_putpointer(va_arg(args, unsigned long long), 0);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (str == NULL)
		return (0);
	count = 0;
	va_start(args, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count += find_specifier(str[i], args);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
/*
int main()
{
	int	mine;
	int	std;
	//int	x = 0;
	//int	*ptr = &x;

    mine=ft_printf("My favourite is: | %p %p |\n", 0, 0);
   printf("%d\n", mine);
    std=printf("My favourite is: | %p %p |\n", 0, 0);
   printf("%d\n", std);


    mine=ft_printf("My favourite is: %x %d %d\n100%%\n",23, -2147483647, 6);
    printf("%d\n", mine);
    std=printf("My favourite is: %x %d %d\n100%%\n", 23, -2147483647, 6);
    printf("%d\n", std);

    mine=ft_printf("The decimal number %d in hexa is %x\n", x, x);
    printf("%d\n", mine);
    std=printf("The decimal number %d in hexa is %x\n", x, x);
    printf("%d\n", std);

    mine=ft_printf("The value of x is %d\n", x);
    printf("%d\n", mine);
    std=printf("The value of x is %d\n", x);
    printf("%d\n", std);

    mine=ft_printf("The address of x is %p\n", &x);
    printf("%d\n", mine);
    std=printf("The address of x is %p\n", &x);
    printf("%d\n", std);


    mine=ft_printf("The value of the pointer is %p\n", ptr);
    printf("%d\n", mine);
    std=printf("The value of the pointer is %p\n", ptr);
    printf("%d\n", std);

    mine=ft_printf("The value pointed to by the pointer is %d\n", *ptr);
    printf("%d\n", mine);
    std=printf("The value pointed to by the pointer is %d\n", *ptr);
    printf("%d\n", std);
   
    return (0);
}
*/
