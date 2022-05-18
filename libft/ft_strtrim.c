/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:12:57 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/18 08:00:25 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1) - 1;
	while (len && ft_strchr(set, s1[len]))
		len--;
	ret = ft_substr((char *)s1, 0, len + 1);
	if (!ret)
	{
		free(ret);
		ret = malloc(sizeof(char));
		if (ret == NULL)
			return (NULL);
		ret[0] = '\0';
	}
	return (ret);
}
