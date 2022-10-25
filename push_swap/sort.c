/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vh.crvlh@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:30:19 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/10/24 21:03:14 by vcarvalh         ###   ########.fr       */
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
	//Veja, node a node qual é o ranking dele e adicione isso a uma nova stack
	//depois dê free na stack original e redirecione stack para a nova stack
	t_list	*ptr;
	t_list	*head;
	t_list	*new_stack;
	int			*nbr;
	int			*rank;

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
	//função que vai retornar qual é o ranking daquele int na stack
	int	*nbr_cmp;
	int	ret;
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
