/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:58:45 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/27 14:13:56 by vcarvalh         ###   ########.fr       */
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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	if (size < 1)
		return (len);
	i = 0;
	while (i < size - 1 && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}


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

char	*ft_strchr(const char *s, int c)
{
	char	find;

	find = (char)c;
	while (*s != find)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	len = s1_len + s2_len;
	ret = malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (ret);
	ft_strlcpy(ret, s1, s1_len + 1);
	ft_strlcat(ret, s2, len + 1);
	return (ret);
}
