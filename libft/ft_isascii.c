/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:29:35 by mbiagi            #+#    #+#             */
/*   Updated: 2024/11/19 10:01:54 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isascii(int c)
{
	if ((c >= 0) && (c <= 127))
		return (1024);
	return (0);
}
/* 
int main(void)
{
	char	c;
	int		x;
	
	c = 'o';
	x = ft_isascii(c);
	if (x == 0)
		printf("non ascii");
	else
		printf("ascii");
	return(0);
} */