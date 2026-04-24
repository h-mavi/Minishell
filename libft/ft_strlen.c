/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 08:29:28 by mbiagi            #+#    #+#             */
/*   Updated: 2025/01/27 11:18:20 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	x;

	x = 0;
	while (s[x] != 0)
		x++;
	return (x);
}
/* 
int main(void)
{
	char	*c;
	int		x;
	
	c = "";
	x = ft_strlen(c);
	printf("%d", x);
	return(0);
} */