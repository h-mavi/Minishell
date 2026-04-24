/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:47:45 by mbiagi            #+#    #+#             */
/*   Updated: 2024/12/10 12:12:00 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_un(unsigned int n)
{
	char	prin;
	long	nret;
	int		i;

	nret = (long)n;
	prin = ' ';
	i = 0;
	if (n >= 10)
		ft_putnbr_un(n / 10);
	prin = (n % 10) + '0';
	write(1, &prin, 1);
	while ((nret / 10) > 0)
	{
		i++;
		nret = nret / 10;
	}
	return (i + 1);
}
