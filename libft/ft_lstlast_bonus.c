/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:44:41 by mbiagi            #+#    #+#             */
/*   Updated: 2024/12/05 09:04:20 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst -> next;
	return (lst);
}
/* 
int main()
{
	t_list	**lst = (t_list **)malloc(sizeof(t_list *) * 3);
	t_list	*p1 = ft_lstnew("ciao");
	t_list	*p2 = ft_lstnew("mondo");
	t_list	*p3 = ft_lstnew("bastardo");
	ft_lstadd_front(lst, p3);
	ft_lstadd_front(lst, p2);
	ft_lstadd_front(lst, p1);
	printf("%s\n", (char *)(ft_lstlast(*lst))->content);
} */