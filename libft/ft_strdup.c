/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:58:09 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/12 14:09:39 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*ret;

	size = ft_strlen(s);
	ret = malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (ret);
	ft_strlcpy(ret, s, size + 1);
	return (ret);
}
