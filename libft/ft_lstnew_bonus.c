/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:16:50 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/21 13:37:53 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	node->content = content;
	node->next = NULL;
	return (node);
}

int main(void)
{
	void	*content;
	t_list	*begin;

	content = malloc(sizeof(int));
	*content = (void)42;
	begin = ft_lstnew(content);
	printf("%d\n", begin->content);
}
