/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:58:45 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/07/21 09:30:08 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	find;

	find = (unsigned char)c;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == find)
			return ((char *) s);
		s++;
	}
	if (find == 0)
		return ((char *)s);
	return ((void *)0);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*line;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return ((void *)0);
	line = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (line == (void *)0)
		return ((void *)0);
	i = -1;
	j = 0;
	while (s1[++i])
		line[i] = s1[i];
	while (s2[j] != '\0')
		line[i++] = s2[j++];
	line[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (line);
}
