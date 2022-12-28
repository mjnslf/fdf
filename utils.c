#include "push_swap.h"
#include "libft.h"

t_stack	*ft_listlast(t_stack *lst)
{
	t_stack	*l;

	l = lst;
	if (l != NULL)
	{
		while ((*l).next != NULL)
			l = (*l).next;
		return (l);
	}
	return (NULL);
}	

t_stack	*ft_listback(t_stack **lst, t_stack *new)
{	
	t_stack	*last;

	if (!new)
		return (NULL);
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_listlast(*lst);
		(*last).next = new;
	}
	return (*lst);
}

t_stack	*ft_lstinit(int content)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(*stack));
	if (!stack)
		return (NULL);
	stack->val = content;
	stack->next = NULL;
	return (stack);
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print)
		write(1, "rrr\n", 4);
}

void	ft_listclear(t_stack **lst)
{
	t_stack	*p;
	t_stack	*t;

	if (!lst || !(*lst))
		return ;
	t = *lst;
	while (t != NULL)
	{
		p = (*t).next;
		free(t);
		t = p;
	}
	*lst = NULL;
}
