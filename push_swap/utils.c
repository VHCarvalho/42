/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vh.crvlh@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 20:33:33 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/10/23 16:33:23 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Tasklist:
// -Receber os argumentos e armazenar em um linked list na ordem correta
// -Criar uma linked list paralela
// -Fazer as funções que são pedidas:
// V-sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
// V-sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
// V-ss: sa and sb at the same time.
// V-pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
// V-pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
// V-ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
// V-rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
// V-rr : ra and rb at the same time.
// V-rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
// V-rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
// V-rrr : rra and rrb at the same time.

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
	return (stacks_ptr);
}

void	ft_stkfree_stacks(t_list **stacks_ptr)
{
	t_list	*ptr;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = stacks_ptr[0];
	stack_b = stacks_ptr[1];
	while (stack_a->next != NULL)
	{
		ptr = stack_a->next;
		ft_lstdelone(stack_a, free);
		stack_a = ptr;
	}
	ft_lstdelone(stack_a, free);
	while (stack_b->next != NULL)
	{
		ptr = stack_b->next;
		ft_lstdelone(stack_b, free);
		stack_b = ptr;
	}
	ft_lstdelone(stack_b, free);
	free(stacks_ptr);
}

t_list	**ft_stkpush_to_stack(t_list **stacks_ptr, int src, int dst)
{
	t_list	*swap;
	t_list	*stk_src;
	t_list	*stk_dst;

	stk_src = stacks_ptr[src];
	if (stk_src->content == NULL)
		return (stacks_ptr);
	stk_dst = stacks_ptr[dst];
	swap = stk_src;
	if (stk_src->next != NULL)
		stk_src = stk_src->next;
	else
		stk_src = ft_lstnew(NULL);
	if (stk_dst->content == NULL)
	{
		ft_lstdelone(stk_dst, free);
		swap->next = NULL;
	}
	else
		swap->next = stk_dst;
	stk_dst = swap;
	stacks_ptr[src] = stk_src;
	stacks_ptr[dst] = stk_dst;
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
	return (stack);
}

t_list	**ft_stkpush(t_list **stack, int *content)
{
	t_list	*ptrstk;

	ptrstk = *stack;
	if (ptrstk->content == NULL)
	{
		ft_lstdelone(ptrstk, free);
		ptrstk = ft_lstnew(content);
	}
	else
		ft_lstadd_front(stack, ft_lstnew(content));
	return (stack);
}