/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:24:24 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/22 14:31:21 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int			ret;

	if (!lst)
		return (0);
	ptr = lst;
	ret = 1;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
		ret++;
	}
	return (ret);
}
