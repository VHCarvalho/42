/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:41:16 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/22 15:53:03 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*tmp;

	if (!del)
		return ;
	if (*lst)
	{
		ptr = *lst;
		while (ptr->next != NULL)
		{
			tmp = ptr;
			del(tmp->content);
			free(tmp);
			ptr = tmp->next;
		}
		*lst = NULL;
	}
}
