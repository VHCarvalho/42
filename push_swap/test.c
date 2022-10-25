/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:53:42 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/10/24 12:59:23 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stacks(t_list	**stacks_ptr)
{
	int	*nbr;

	if (stack_sorted(stacks_ptr))
		printf("stacks sorted\n");
	else
		printf("stacks not sorted\n");
	while (stacks_ptr[0]->next != NULL)
	{
		nbr = stacks_ptr[0]->content;
		printf("%d\n", *nbr);
		stacks_ptr[0] = stacks_ptr[0]->next;
	}
	nbr = stacks_ptr[0]->content;
	if (!nbr)
		printf("NULL\n");
	else
		printf("%d\n", *nbr);
	printf("--------\n");
	while (stacks_ptr[1]->next != NULL)
	{
		nbr = stacks_ptr[1]->content;
		printf("%d\n", *nbr);
		stacks_ptr[1] = stacks_ptr[1]->next;
	}
	nbr = stacks_ptr[1]->content;
	if (!nbr)
		printf("NULL\n");
	else
		printf("%d\n", *nbr);
}
