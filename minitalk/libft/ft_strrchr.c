/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:58:27 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/19 09:17:04 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	find;

	find = (char)c;
	len = ft_strlen(s);
	while (s[len] != find)
	{
		if (len == 0)
			return (0);
		len--;
	}
	return ((char *)&s[len]);
}
