/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:37:30 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/17 08:33:37 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ret;
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	ret = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	dst += dstlen;
	if (size > dstlen)
		ret = srclen + dstlen;
	else
		ret = srclen + size;
	i = 0;
	if (dstlen < size - 1 && size > 0)
	{
		while (src[i] && dstlen + i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (ret);
}
