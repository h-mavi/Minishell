/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:18:44 by mbiagi            #+#    #+#             */
/*   Updated: 2024/12/07 10:19:18 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lf;
	t_list	*l;

	if (!lst)
		return (NULL);
	l = NULL;
	while (lst)
	{
		lf = ft_lstnew(f(lst->content));
		if (!lf)
			ft_lstdelone(lf, del);
		ft_lstadd_back(&l, lf);
		lst = lst->next;
	}
	return (l);
}
