/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vh.crvlh@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:15:10 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/10/25 17:46:31 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**ft_stkinit(t_list **stacks_ptr, int size, char *nbrs[])
{
	int	*nbr;
	int	i;

	i = 1;
	stacks_ptr[0] = ft_lstnew(NULL);
	stacks_ptr[1] = ft_lstnew(NULL);
	while (i < size)
	{
		nbr = malloc(sizeof(int));
		if (nbr == NULL)
			return (0);
		*nbr = ft_atoi(nbrs[i]);
		ft_stkpush(stacks_ptr, nbr);
		i++;
	}
	return (stacks_ptr);
}

void	ft_stkpush(t_list **stack, int *content)
{
	t_list	*ptrstk;

	if (!stack)
		return ;
	ptrstk = *stack;
	if (!ptrstk->content)
		ptrstk->content = content;
	else
		ft_lstadd_back(stack, ft_lstnew(content));
}
