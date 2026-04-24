/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:55:47 by mbiagi            #+#    #+#             */
/*   Updated: 2024/12/05 14:34:30 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return ;
	if (!lst)
		(*lst) = new;
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
/* 
int main()
{
	t_list	**lst = (t_list **)malloc(sizeof(t_list *) * 3);
	t_list	*p1 = ft_lstnew("ciao");
	t_list	*p2 = ft_lstnew("mondo");
	t_list	*p3 = ft_lstnew("bastardo");
	ft_lstadd_back(lst, p1);
	ft_lstadd_back(lst, p2);
	ft_lstadd_back(lst, p3);
	while (*lst)
	{
		printf("%s\n", (char *)(*lst)->content);
		*lst = (*lst)->next;
	}
} */