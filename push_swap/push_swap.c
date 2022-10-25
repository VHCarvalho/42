/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vh.crvlh@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:52:51 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/10/25 16:35:04 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	**stacks_ptr;

	if (argc == 1)
		return (0);
	stacks_ptr = malloc(sizeof(t_list *) * 2);
	if (stacks_ptr == NULL)
		return (0);
	stacks_ptr = ft_stkinit(stacks_ptr, argc, argv);
	redo_stack(stacks_ptr);
	if (ft_lstsize(stacks_ptr[0]) > 5)
		radix_sort(stacks_ptr);
	else
		small_stack_sort(stacks_ptr);
	ft_stkfree_stack(stacks_ptr[0]);
	ft_stkfree_stack(stacks_ptr[1]);
	free(stacks_ptr);
	return (0);
}
