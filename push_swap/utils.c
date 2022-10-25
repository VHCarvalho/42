/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vh.crvlh@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:33:33 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/10/25 16:02:14 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**ft_stkrev_rotate(t_list **stacks_ptr, int stkindex)
{
	t_list	*ptrhead;
	t_list	*ptrlast;
	t_list	*new_last;

	ptrhead = stacks_ptr[stkindex];
	if (ptrhead->next == NULL)
		return (stacks_ptr);
	new_last = ptrhead;
	while (new_last->next->next != NULL)
		new_last = new_last->next;
	ptrlast = new_last->next;
	ptrlast->next = ptrhead;
	new_last->next = NULL;
	stacks_ptr[stkindex] = ptrlast;
	if (stkindex == 0)
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
	return (stacks_ptr);
}

t_list	**ft_stkrotate(t_list	**stacks_ptr, int stkindex)
{
	t_list	*ptrhead;
	t_list	*ptrlast;
	t_list	*new_head;

	ptrhead = stacks_ptr[stkindex];
	if (ptrhead->next == NULL)
		return (stacks_ptr);
	new_head = ptrhead->next;
	ptrlast = ft_lstlast(ptrhead);
	ptrlast->next = ptrhead;
	ptrhead->next = NULL;
	stacks_ptr[stkindex] = new_head;
	if (stkindex == 0)
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
	return (stacks_ptr);
}

void	ft_stkfree_stack(t_list *stack)
{
	t_list	*ptr;

	if (!stack)
		return ;
	while (stack->next != NULL)
	{
		ptr = stack->next;
		ft_lstdelone(stack, free);
		stack = ptr;
	}
	ft_lstdelone(stack, free);
}

t_list	**ft_stkpush_to_stack(t_list **stacks_ptr, int src, int dst)
{
	t_list	*swap;

	if (stacks_ptr[src]->content == NULL)
		return (stacks_ptr);
	swap = stacks_ptr[src];
	if (stacks_ptr[src]->next != NULL)
		stacks_ptr[src] = stacks_ptr[src]->next;
	else
		stacks_ptr[src] = ft_lstnew(NULL);
	if (stacks_ptr[dst]->content == NULL)
	{
		ft_lstdelone(stacks_ptr[dst], free);
		swap->next = NULL;
	}
	else
		swap->next = stacks_ptr[dst];
	stacks_ptr[dst] = swap;
	if (dst == 1)
		ft_putstr_fd("pb\n", 1);
	else
		ft_putstr_fd("pa\n", 1);
	return (stacks_ptr);
}

t_list	*ft_stkswap(t_list *stack)
{
	t_list	*swap_a;
	t_list	*swap_b;

	if (stack->content == NULL || stack->next == NULL)
		return (stack);
	swap_a = stack;
	swap_b = stack->next;
	swap_a->next = swap_b->next;
	swap_b->next = swap_a;
	stack = swap_b;
	ft_putstr_fd("sa\n", 1);
	return (stack);
}
