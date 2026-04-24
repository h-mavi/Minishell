/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:46:49 by mbiagi            #+#    #+#             */
/*   Updated: 2025/01/27 09:37:34 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checks(char *input, int *i, int *len, va_list arg)
{
	if (input[*i] != '%')
		return (0);
	if (input[*i] == '\0')
		return (1);
	if (input[*i + 1] == '%')
		*len += ft_putchar('%', 1);
	if (input[*i + 1] == 'c')
		*len += ft_putchar(va_arg(arg, int), 1);
	else if (input[*i + 1] == 's')
		*len += ft_putstr(va_arg(arg, char *), 1);
	else if ((input[*i + 1] == 'd') || (input[*i + 1] == 'i'))
		*len += ft_putnbr(va_arg(arg, int), 1);
	else if (input[*i + 1] == 'u')
		*len += ft_putnbr_un(va_arg(arg, unsigned int));
	else if (input[*i + 1] == 'x')
		*len += ft_putnbr_hex(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (input[*i + 1] == 'X')
		*len += ft_putnbr_hex(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (input[*i + 1] == 'p')
		*len += ft_putnbr_long(va_arg(arg, unsigned long long), \
		"0123456789abcdef");
	return ((*i)++, 1);
}

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	int		i;
	int		len;

	i = 0;
	if (!input)
		return (-1);
	len = 0;
	va_start(arg, input);
	while (input[i])
	{
		if (ft_checks((char *)input, &i, &len, arg) == 0)
		{
			write(1, &input[i], 1);
			len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
/* 
int main (void)
{
	// char *a = "p";
	int x = 0;
	x = printf("%s%d", "ciao", 12);
	printf("   %d\n", x);
	x = ft_printf("%s%d", "ciao", 12);
	printf("   %d\n", x);
	return (0);
} */