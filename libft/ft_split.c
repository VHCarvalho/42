/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:12:56 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/19 17:55:46 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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

char	**ft_split(char const *s, char c)
{
	char		**ret;
	size_t	count;
	size_t	i;
	size_t	len;
	size_t	j;

	count = count_words((char *)s, c);
	ret = ft_calloc(count + 1, sizeof(char **));
	if (!s || !ret)
		return (NULL);
	i = 0;
	j = 0;
	while (i < count)
	{
		if (i == 0 && s[j] == c)
		{
			j++;
			continue ;
		}
		if (i == 0 && s[j] != c)
		{
			len = word_len(s + j, c);
			ret[i] = ft_substr(s, j, len);
			s = ft_strchr(s + j, c);
			j = 0;
			i++;
			continue ;
		}
		else if (s[j] != c && s[j - 1] == c && i > 0)
		{
			len = word_len(s + j, c);
			ret[i] = ft_substr(s, j, len);
			s = ft_strchr(s + j, c);
			j = 0;
			i++;
			continue ;
		}
		j++;
	}
	ret[i] = '\0';
	return (ret);
}
/*
int	main(void)
{
	char	s[] = "aaaaaavamos aaaaaa la playa";
	char	c = 'a';
	char	**ret;
	int		i;

	i = 0;
	ret = ft_split(s, c);
	printf("começando\n");
	while(ret[i])
	{
		printf("ret: %s\n", ret[i]);
		i++;
	}
	i++;
	while (i >= 0)
	{
		free(ret[i]);
		i--;
	}
}*/
