/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:52:13 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/10/25 17:45:36 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_stack_sort(t_list **stacks_ptr)
{
	int	stack_size;

	if (stack_sorted(stacks_ptr))
		return ;
	stack_size = ft_lstsize(stacks_ptr[0]);
	if (stack_size < 3)
		stacks_ptr[0] = ft_stkswap(stacks_ptr[0]);
	else if (stack_size == 3)
		expected_sort(stacks_ptr);
	else
		sort_5stack(stacks_ptr);
}

void	sort_5stack(t_list **stacks_ptr)
{
	int	stack_size;
	int	i;
	int	*nbr;

	stack_size = ft_lstsize(stacks_ptr[0]);
	i = 0;
	while (stack_size - i > 3)
	{
		nbr = stacks_ptr[0]->content;
		if (*nbr == i)
		{
			stacks_ptr = ft_stkpush_to_stack(stacks_ptr, 0, 1);
			i++;
		}
		else if (worst_case(stacks_ptr, i))
			stacks_ptr = ft_stkrev_rotate(stacks_ptr, 0);
		else
			stacks_ptr = ft_stkrotate(stacks_ptr, 0);
	}
	expected_sort(stacks_ptr);
	stacks_ptr = ft_stkpush_to_stack(stacks_ptr, 1, 0);
	stacks_ptr = ft_stkpush_to_stack(stacks_ptr, 1, 0);
}

int	worst_case(t_list **stacks_ptr, int i)
{
	t_list	*ptr;
	int		*nbr;

	ptr = stacks_ptr[0];
	while (ptr->next != NULL)
		ptr = ptr->next;
	nbr = ptr->content;
	if (*nbr == i)
		return (1);
	return (0);
}

void	expected_sort(t_list	**stacks_ptr)
{
	int		*nbr1;
	int		*nbr2;
	int		*nbr3;
	t_list	*ptr;

	ptr = stacks_ptr[0];
	nbr1 = NULL;
	while (ptr->next != NULL)
	{
		if (!nbr1)
			nbr1 = ptr->content;
		else
			nbr2 = ptr->content;
		ptr = ptr->next;
	}
	nbr3 = ptr->content;
	check_cases(stacks_ptr, nbr1, nbr2, nbr3);
}

void	check_cases(t_list **stacks_ptr, int *nbr1, int *nbr2, int *nbr3)
{
	if (*nbr1 < *nbr2 && *nbr1 < *nbr3 && *nbr1 == *nbr2 - 2)
	{
		stacks_ptr = ft_stkrev_rotate(stacks_ptr, 0);
		stacks_ptr[0] = ft_stkswap(stacks_ptr[0]);
	}
	else if (*nbr1 > *nbr2 && *nbr1 > *nbr3 && *nbr1 == *nbr2 + 1)
	{
		stacks_ptr[0] = ft_stkswap(stacks_ptr[0]);
		stacks_ptr = ft_stkrev_rotate(stacks_ptr, 0);
	}
	if (*nbr1 < *nbr2 && *nbr1 > *nbr3 && *nbr1 == *nbr2 - 1)
		stacks_ptr = ft_stkrev_rotate(stacks_ptr, 0);
	if (*nbr1 > *nbr2 && *nbr1 < *nbr3 && *nbr1 == *nbr2 + 1)
		stacks_ptr[0] = ft_stkswap(stacks_ptr[0]);
	if (*nbr1 > *nbr2 && *nbr1 > *nbr3 && *nbr1 == *nbr2 + 2)
		stacks_ptr = ft_stkrotate(stacks_ptr, 0);
}
