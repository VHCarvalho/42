/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:18:45 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/22 14:34:24 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;
	size_t	total;

	total = nmemb * size;
	if (total / nmemb != size)
		return (NULL);
	ret = malloc(total);
	if (ret == NULL)
		return (ret);
	ft_bzero(ret, total);
	return (ret);
}
