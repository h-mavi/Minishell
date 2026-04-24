/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:13:20 by mbiagi            #+#    #+#             */
/*   Updated: 2024/12/03 14:29:12 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new -> next = *lst;
	*lst = new;
}
/* 
int main()
{
	int i = 0;
	t_list	**lst = (t_list **)malloc(sizeof(t_list *) * 3);
	t_list	*p1 = ft_lstnew("ciao");
	t_list	*p2 = ft_lstnew("mondo");
	t_list	*p3 = ft_lstnew("bastardo");
	ft_lstadd_front(lst, p3);
	ft_lstadd_front(lst, p2);
	ft_lstadd_front(lst, p1);
	while ((*lst)->next)
	{
		printf("%d: %s\n", i, (char *)(*lst)->content);
		*lst = (*lst)->next;
		i++;
	}
	printf("%d: %s\n", i, (char *)(*lst)->content);
} */