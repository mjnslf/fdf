/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgregoro <mgregoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:48:59 by ykareen           #+#    #+#             */
/*   Updated: 2021/11/23 10:49:24 by mgregoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_free(t_nbr	*nbr, t_list **begin_a, t_list **begin_b, int err)
{
	if (begin_a != NULL)
		ft_lstclear(begin_a);
	if (begin_b != NULL)
		ft_lstclear(begin_b);
	if (nbr != NULL)
		free(nbr);
	if (err == 1)
		write (1, "Error\n", 6);
	return (0);
}

int	ft_parser(int ac, char **av, t_list **begin)
{
	int		i;
	t_nbr	*nbr;
	t_list	*lst;

	i = 1;
	nbr = malloc(sizeof(t_nbr));
	while (i < ac)
	{
		nbr->is_int = 1;
		ft_atoi_light(nbr, av[i]);
		if (nbr->is_int == 1)
		{
			lst = ft_lstnew(nbr->nbr);
			if (lst == NULL)
				return (ft_free(nbr, begin, NULL, 1));
			lst->n = -1;
			lst->gr = 0;
			ft_lstadd_back(begin, lst);
		}
		else
			return (ft_free(nbr, begin, NULL, 1));
		i++;
	}
	ft_free (nbr, NULL, NULL, 0);
	return (1);
}

// assending numbering 0 to N list items. Recurse

void	ft_bubble_sort(t_list *lst, int k, int size)
{
	t_list	*min;	
	t_list	*buff;

	min = NULL;
	buff = lst;
	if (k == size)
		return ;
	while (lst)
	{
		if (lst->n == -1)
		{
			min = lst;
			break ;
		}
		lst = lst->next;
	}
	while (lst)
	{
		if (lst->nbr < min->nbr && lst->n == -1)
			min = lst;
		lst = lst->next;
	}
	min->n = k;
	ft_bubble_sort(buff, k + 1, size);
	return ;
}

int	ft_check_doubl(t_list *lst, int k, int size, int before)
{
	t_list	*buff;

	if (size == 1 || k == size)
		return (0);
	buff = lst;
	while (lst)
	{
		if (lst->n == k)
			break ;
		if (lst->n == -2)
			return (0);
		lst = lst->next;
	}
	if (lst->nbr == before && k > 0)
		buff->n = -2;
	ft_check_doubl(buff, k + 1, size, lst->nbr);
	if (buff->n == -2)
		return (1);
	return (0);
}

// MIN defined throut the pointer because all items of the lists can
// view this MIN and any item can change this MIN for every one
// The same way for COUNTER

void	ft_init_general(t_list *lst, int *min, int *counter)
{
	*min = 0;
	*counter = 0;
	while (lst)
	{
		lst->min = min;
		lst->counter = counter;
		lst = lst->next;
	}
}
