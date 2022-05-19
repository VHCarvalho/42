/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 08:45:57 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/19 10:40:14 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s) - start >= len)
        ret = malloc(sizeof(*s) * (len + 1));
    else
        ret = malloc(sizeof(*s) * (ft_strlen(s) - start + 1));
    if (!ret)
        return (NULL);
	ft_strlcpy(ret, &s[start], len + 1);
	return (ret);
}
