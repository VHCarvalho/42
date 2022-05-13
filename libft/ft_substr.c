/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 08:45:57 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/13 10:03:57 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s)
		return (NULL);
	ret = malloc(sizeof(char) * len + 1);
	if (ret == NULL)
		return (ret);
	if (ft_strlen(s) < start)
	{
		ret[0] = '\0';
		return (ret);
	}
	ft_strlcpy(ret, &s[start], len + 1);
		return (ret);
}
