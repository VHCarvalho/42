/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:26:03 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/17 10:53:35 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	int				ret;

	if (n <= 0)
		return (0);
	i = 0;
	ret = 0;
	while (s1[i] == s2[i] && i < n - 1 && s1[i] && s2[i])
		i++;
	ret = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (ret);
}
