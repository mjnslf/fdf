/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   already_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgregoro <mgregoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:15:27 by mgregoro          #+#    #+#             */
/*   Updated: 2021/11/30 14:16:01 by mgregoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_list **begin_a, t_list **begin_b)
{
	int		n;
	t_list	*lst;

	lst = *begin_a;
	if (*begin_b != NULL || *begin_a == NULL)
		return (0);
	n = lst->n;
	lst = lst->next;
	while (lst)
	{
		if (lst->n < n)
			return (0);
		n = lst->n;
		lst = lst->next;
	}
	return (1);
}
