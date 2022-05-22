/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:12:56 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/22 12:21:20 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(char *s, char c)
{
	size_t	i;
	size_t	j;
	char	last;

	last = c;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && last == c)
			j++;
		last = s[i];
		i++;
	}
	return (j);
}

size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

void	write_words(char **ret, char const *s, char c, size_t count)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (i < count)
	{
		if (i == 0 && s[j] != c)
		{
			len = word_len(s + j, c);
			ret[i++] = ft_substr(s, j, len);
			s = ft_strchr(s + j, c);
			j = -1;
		}
		else if (s[j] != c && s[j - 1] == c && i > 0)
		{
			len = word_len(s + j, c);
			ret[i++] = ft_substr(s, j, len);
			s = ft_strchr(s + j, c);
			j = -1;
		}
		j++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	count;

	count = count_words((char *)s, c);
		ret = ft_calloc(count + 1, sizeof(char **));
	if (!s || !ret)
		return (NULL);
	write_words(ret, s, c, count);
	ret[count] = '\0';
	return (ret);
}
