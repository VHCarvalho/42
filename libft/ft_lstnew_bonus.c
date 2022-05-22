/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:16:50 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/22 12:54:33 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
int main(void)
{
	t_list	*begin;
	int		*nbr;
	int		*ret;

	nbr = malloc(sizeof(int));
	*nbr = 42;
	printf("%p\n", nbr);
	begin = ft_lstnew(nbr);
	ret = begin->content;
	printf("%d\n", *ret);
}*/
