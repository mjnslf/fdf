/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgregoro <mgregoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:09:33 by mgregoro          #+#    #+#             */
/*   Updated: 2021/11/30 14:10:09 by mgregoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*p;
	t_list	*p1;

	p = *lst;
	*lst = NULL;
	p1 = p;
	while (p)
	{
		p = p->next;
		free(p1);
		p1 = p;
	}
}

t_list	*ft_lstnew(int n)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == 0)
		return (0);
	new->nbr = n;
	new->next = 0;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*p;

	p = *lst;
	*lst = new;
	new->next = p;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lst_before_last(t_list *lst)
{
	if (lst == 0)
		return (0);
	if (lst->next == 0)
		return (0);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}
