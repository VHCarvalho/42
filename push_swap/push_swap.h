/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:10:18 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/10/22 20:39:18 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

t_list *ft_lstadd_front2(t_list *lst, int *content);
void  ft_stkfree_stacks(t_list **stacks_ptr);
t_list  **ft_stkpush_to_stack(t_list **stacks_ptr, int src, int dst);
t_list  *ft_stkswap(t_list *stack);
t_list  *ft_stkpush(t_list *stack, int *content);

#endif
