/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:12:57 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/13 14:37:02 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	len;
	//size_t	j;

	if (!s1 || !set)
		return (NULL);
	while (*s1 || ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len]))
		len--;
	ret = ft_substr((char *)s1, 0, len + 1);
	return (ret);
}

int	main(void)
{
	char	s1[] = "AzzeVamos a la playazezeA";
	char	set[] = "Aze";
	char	*ret;

	ret = ft_strtrim(s1, set);

	printf("%s\n", ret);
	return (0);
}
