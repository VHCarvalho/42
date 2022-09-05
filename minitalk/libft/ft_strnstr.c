/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:39:25 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/19 09:40:09 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (*needle == '\0' || !needle)
		return ((char *)haystack);
	len = ft_strlen(needle);
	if (*haystack == '\0')
		return (0);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (j + i) < n
			&& haystack[i + j] && needle[j])
			j++;
		if (j == len)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
