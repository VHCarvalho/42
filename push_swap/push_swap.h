/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:10:18 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/10/27 08:35:11 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

void	ft_stkfree_stack(t_list *stack);
t_list	**ft_stkpush_to_stack(t_list **stacks_ptr, int src, int dst);
t_list	*ft_stkswap(t_list *stack);
void	ft_stkpush(t_list **stack, int *content);
t_list	**ft_stkrotate(t_list	**stacks_ptr, int stkindex);
t_list	**ft_stkrev_rotate(t_list **stacks_ptr, int stkindex);
t_list	**ft_stkinit(t_list **stacks_ptr, int size, char *nbrs[]);
int		stack_sorted(t_list	**stacks_ptr);
void	redo_stack(t_list	**stacks_ptr);
int		get_rank(t_list *stack, int nbr);
void	radix_sort(t_list **stacks_ptr);
void	small_stack_sort(t_list **stacks_ptr);
void	expected_sort(t_list	**stacks_ptr);
void	check_cases(t_list **stacks_ptr, int *nbr1, int *nbr2, int *nbr3);
int		worst_case(t_list **stacks_ptr, int i);
void	sort_5stack(t_list **stacks_ptr);
int		check_alpha(int argc, char *argv[]);
int		check_maxmin(int argc, char *argv[]);
long	ft_atol(const char *str);
int		check_duplicates(int argc, char *argv[]);
int		check_errors(int argc, char *argv[]);

#endif
