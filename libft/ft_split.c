/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:12:56 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/19 15:44:41 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	count_words(char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
		{
			*s = '\0';
			i++;
		}
		s++;
	}
	if (*(s - 1) != '\0')
		i++;
	return (i);
}

size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	count;
	size_t	i;
	//size_t	len;
	//size_t	j;

	count = count_words((char *)s, c);
	ret = (char **)malloc(sizeof(char *) * count + 1);
	i = 0;
	//j = 0;
	/*while (i < count)
	{
		if (i == 0)
		{
			len = ft_strchr(s, c) - s;
			ret[i] = ft_substr(s, j, len);
			i++;
		}
		if (s[j] == c)
		{
			len = ft_strchr(s + j + 1, c) - s;
			ret[i] = ft_substr(s, j + 1, len);
			i++;
		}
		j++;
	}*/
	while (i < count)
	{
		ret[i] = ft_strdup(s);
		s += ft_strlen(s) + 1;
		i++;
	}
	ret[i] = malloc(sizeof(char *));
	ret[i][0] = '\0';
	return (ret);
}

int	main(void)
{
	char	s[] = "vzzzzaxxxxmos a xxxxla plxxxayxxxxa";
	char	c = 'a';
	char	**ret;
	int		i;

	i = 0;
	ret = ft_split(s, c);
	while(ret[i])
	{
		printf("ret: %s\n", ret[i]);
		i++;
	}
}
