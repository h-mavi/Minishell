/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:47:42 by mbiagi            #+#    #+#             */
/*   Updated: 2024/11/19 10:02:05 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1024);
	return (0);
}
/* 
int main(void)
{
	char	c;
	int		x;
	
	c = 'o';
	x = ft_isdigit(c);
	if (x == 0)
		printf("non digit");
	else
		printf("digit");
	return(0);
} */