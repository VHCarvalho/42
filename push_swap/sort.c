/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vh.crvlh@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:30:19 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/10/25 14:57:41 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_list	**stacks_ptr)
{
	t_list	*ptr;
	int		*nbr_a;
	int		*nbr_b;

	ptr = stacks_ptr[0];
	if (!ptr)
		return (1);
	nbr_a = ptr->content;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		nbr_b = ptr->content;
		if (*nbr_a > *nbr_b)
			return (0);
		nbr_a = nbr_b;
	}
	return (1);
}

void	redo_stack(t_list	**stacks_ptr)
{
	t_list	*ptr;
	t_list	*head;
	t_list	*new_stack;
	int		*nbr;
	int		*rank;

	new_stack = ft_lstnew(NULL);
	ptr = stacks_ptr[0];
	head = ptr;
	while (ptr->next != NULL)
	{
		nbr = ptr->content;
		rank = malloc(sizeof(int));
		*rank = get_rank(head, *nbr);
		ft_stkpush(&new_stack, rank);
		ptr = ptr->next;
	}
	nbr = ptr->content;
	rank = malloc(sizeof(int));
	*rank = get_rank(head, *nbr);
	ft_stkpush(&new_stack, rank);
	stacks_ptr[0] = new_stack;
	ft_stkfree_stack(head);
}

int	get_rank(t_list *stack, int nbr)
{
	int		*nbr_cmp;
	int		ret;
	t_list	*ptr;

	ret = 0;
	ptr = stack;
	while (ptr->next != NULL)
	{
		nbr_cmp = ptr->content;
		if (nbr > *nbr_cmp)
			ret++;
		ptr = ptr->next;
	}
	nbr_cmp = ptr->content;
	if (nbr > *nbr_cmp)
		ret++;
	return (ret);
}

int	stack_empty(t_list	*stack)
{
	if (!stack->content)
		return (1);
	return (0);
}

void	radix_sort(t_list **stacks_ptr)
{
	int			i;
	int			j;
	int			*nbr;
	int			stack_size;

	i = 0;
	stack_size = ft_lstsize(stacks_ptr[0]);
	while (!stack_sorted(stacks_ptr))
	{
		j = 0;
		while (j < stack_size)
		{
			nbr = stacks_ptr[0]->content;
			if (((*nbr >> i) & 1) == 1)
				stacks_ptr = ft_stkrotate(stacks_ptr, 0);
			else
				stacks_ptr = ft_stkpush_to_stack(stacks_ptr, 0, 1);
			j++;
		}
		while (!stack_empty(stacks_ptr[1]))
			stacks_ptr = ft_stkpush_to_stack(stacks_ptr, 1, 0);
		i++;
	}
}
