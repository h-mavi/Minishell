/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:43:00 by mbiagi            #+#    #+#             */
/*   Updated: 2024/11/19 10:02:10 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalpha(int c)
{
	if (((c > 64) && (c < 91)) || ((c > 96) && (c < 123)))
		return (1024);
	return (0);
}
/* 
int main(void)
{
	char	c;
	int		x;
	
	c = 'h';
	x = ft_isalpha(c);
	if (x == 0)
		printf("non alpha");
	else
		printf("alpha");
	return(0);
} */
