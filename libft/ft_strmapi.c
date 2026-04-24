/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:49:43 by mbiagi            #+#    #+#             */
/*   Updated: 2024/12/02 15:27:58 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*sft;
	int		i;

	i = 0;
	while (s[i])
		i++;
	sft = malloc(sizeof(char) * (i + 1));
	if (sft == NULL)
		return (NULL);
	sft[i] = '\0';
	i--;
	while (i >= 0)
	{
		sft[i] = f(i, s[i]);
		i--;
	}
	return (sft);
}
/* 
int	main(void)
{
	char	*s;

	s = "peperoni";
	s = ft_strmapi(s);
	
} */