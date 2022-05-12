/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:28:46 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/12 10:47:27 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				ret;
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)&s1;
	ptr2 = (unsigned char *)&s2;
	ret = 0;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
		{
			ret = ptr1[i] - ptr2[i];
			break ;
		}
		i++;
	}
	return (ret);
}
