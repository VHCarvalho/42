/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vh.crvlh@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:52:51 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/10/22 20:40:16 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>



int main(int argc, char *argv[])
{
	int			*nbr;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	**stacks_ptr;
	int			count;

	if (argc == 1)
		return (0);
	count = 1;
	stacks_ptr = malloc(sizeof(t_list*) * 2);
	if (stacks_ptr == NULL)
		return (0);
	stacks_ptr[0] = ft_lstnew(NULL);
	stacks_ptr[1] = ft_lstnew(NULL);
	while (count < argc)
	{
		nbr = malloc(sizeof(int));
		if (nbr == NULL)
			return (0);
		*nbr = ft_atoi(argv[count]);
		stacks_ptr[0] = ft_stkpush(stacks_ptr[0], nbr);
		count++;
	}
	stacks_ptr[0] = ft_stkswap(stacks_ptr[0]);
	stacks_ptr = ft_stkpush_to_stack(stacks_ptr, 0, 1);
	stacks_ptr = ft_stkpush_to_stack(stacks_ptr, 0, 1);
	stacks_ptr = ft_stkpush_to_stack(stacks_ptr, 0, 1);
	stack_a = stacks_ptr[0];
	stack_b = stacks_ptr[1];
	while (stacks_ptr[0]->next != NULL)
	{
		nbr = stacks_ptr[0]->content;
		printf("%d\n", *nbr);
		stacks_ptr[0] = stacks_ptr[0]->next;
	}
	nbr = stacks_ptr[0]->content;
	printf("%d\n", *nbr);
	printf("--------\n");
	while (stacks_ptr[1]->next != NULL)
	{
		nbr = stacks_ptr[1]->content;
		printf("%d\n", *nbr);
		stacks_ptr[1] = stacks_ptr[1]->next;
	}
	nbr = stacks_ptr[1]->content;
	printf("%d\n", *nbr);
	stacks_ptr[0] = stack_a;
	stacks_ptr[1] = stack_b;
	ft_stkfree_stacks(stacks_ptr);
	return (0);
}

