/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:25:55 by mbiagi            #+#    #+#             */
/*   Updated: 2024/12/05 09:04:46 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*l;

	if (lst)
	{
		while (*lst)
		{
			l = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = l;
		}
		*lst = NULL;
	}
}
