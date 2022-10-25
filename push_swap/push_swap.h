/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:10:18 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/10/25 11:30:27 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

void  ft_stkfree_stack(t_list *stack);
t_list  **ft_stkpush_to_stack(t_list **stacks_ptr, int src, int dst);
t_list  *ft_stkswap(t_list *stack);
void	ft_stkpush(t_list **stack, int *content);
t_list	**ft_stkrotate(t_list	**stacks_ptr, int stkindex);
t_list	**ft_stkrev_rotate(t_list **stacks_ptr, int stkindex);
t_list	**ft_stkinit(t_list **stacks_ptr, int size, char *nbrs[]);
int	stack_sorted(t_list	**stacks_ptr);
void	redo_stack(t_list	**stacks_ptr);
int	get_rank(t_list *stack, int nbr);
void radix_sort(t_list **stacks_ptr);
//apagar
void	print_stacks(t_list	**stacks_ptr);

#endif
