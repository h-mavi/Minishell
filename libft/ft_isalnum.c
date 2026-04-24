/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:13:17 by mbiagi            #+#    #+#             */
/*   Updated: 2024/11/19 10:01:59 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalnum(int c)
{
	if (((c > 64) && (c < 91)) || ((c > 96) && (c < 123)) || \
	((c >= 48) && (c <= 57)))
		return (8);
	return (0);
}
/* 
int main(void)
{
	char	c;
	int		x;
	
	c = 't';
	x = ft_isalnum(c);
	if (x == 0)
		printf("non alnum");
	else
		printf("alnum");
	return(0);
} */