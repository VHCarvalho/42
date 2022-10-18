/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:52:51 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/10/18 17:06:05 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

// Tasklist:
// -Receber os argumentos e armazenar em um linked list na ordem correta
// -Criar uma linked list paralela
// -Fazer as funções que são pedidas:
// --sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
// --sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
// --ss: sa and sb at the same time.
// --pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
// --pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
// --ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
// --rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
// --rr : ra and rb at the same time.
// --rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
// --rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
// --rrr : rra and rrb at the same time.

int main(int argc, char *argv[])
{
	int		count;
	t_list	*stack_a;
	t_list	*tmp;
	
	count = 1;
	while (count < argc)
	{
		if (count == 1)
			stack_a = ft_lstnew(argv[count]);
		else
			tmp = ft_lstnew(argv[count]);
			ft_lstadd_front(stack_a, tmp);
		count++;
	}

	while 
	return (0);
}
