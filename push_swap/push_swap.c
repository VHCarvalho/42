/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:52:51 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/10/21 19:04:52 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

// Tasklist:
// -Receber os argumentos e armazenar em um linked list na ordem correta
// -Criar uma linked list paralela
// -Fazer as funções que são pedidas:
// V-sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
// V-sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
// V-ss: sa and sb at the same time.
// --pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
// --pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
// --ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
// --rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
// --rr : ra and rb at the same time.
// --rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
// --rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
// --rrr : rra and rrb at the same time.

t_list *ft_lstadd_front2(t_list	*lst, int *content)
{
	t_list	*node;

	node = ft_lstnew(content);
	node->next = lst;
	lst = node;
	return (lst);
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

t_list	*ft_stkpush(t_list *stack, int *content)
{
	if (stack->content == NULL)
		stack->content = content;
	else
		stack = ft_lstadd_front2(stack, content);
	return (stack);
}

int main(int argc, char *argv[])
{
	int			*nbr;
	t_list	*stack_a;
	t_list	*stack_b;
	int			count;

	if (argc == 1)
		return (0);
	count = 1;
	stack_a = ft_lstnew(NULL);
	stack_b = ft_lstnew(NULL);
	while (count < argc)
	{
		nbr = malloc(sizeof(int));
		if (nbr == NULL)
			return (0);
		*nbr = ft_atoi(argv[count]);
		stack_a = ft_stkpush(stack_a, nbr);
		count++;
	}
	stack_a = ft_stkswap(stack_a);
	while (stack_a->next != NULL)
	{
		nbr = stack_a->content;
		printf("%d\n", *nbr);
		stack_a = stack_a->next;
	}
	nbr = stack_a->content;
	printf("%d\n", *nbr);
	if (stack_b->content == NULL)
		return (0);
	return (0);
}

