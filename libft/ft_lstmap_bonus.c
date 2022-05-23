/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:28:29 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/23 13:44:43 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_new(t_list *new, t_list *lst, t_list *head, void (*del)(void *))
{
	if (!new)
	{
		ft_lstclear(&lst, del);
		ft_lstclear(&head, del);
		return (1);
	}
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	head = new;
	if (check_new(new, lst, head, del))
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (check_new(new, lst, head, del))
			break ;
		lst = lst->next;
		ft_lstadd_back(&head, new);
	}
	ft_lstclear(&lst, del);
	return (head);
}
