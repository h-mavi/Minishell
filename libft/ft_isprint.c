/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:01:49 by mbiagi            #+#    #+#             */
/*   Updated: 2024/11/29 09:18:35 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isprint(int c)
{
	if ((c >= 32) && (c <= 126))
		return (16384);
	return (0);
}
/* 
int main(void)
{
	char	c;
	int		x;
	
	c = 0;
	x = ft_isprint(c);
	if (x == 0)
		printf("non print");
	else
		printf("print");
	return(0);
} */