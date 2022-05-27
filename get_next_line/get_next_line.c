/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:32:20 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/27 17:42:33 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buff;
	char		*line;
	char		*tmp;
	size_t		len;
	int			check;

	if (fd < 0)
		return (NULL);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	len = 0;
	line = NULL;
	check = read(fd, buff, BUFFER_SIZE);
	printf("check: %d\n", check);
	if (check == 0)
		return (stash);
	else if (check < 0)
		return (NULL);
	while (check > 0)
	{
		stash = ft_strjoin(stash, buff);
		printf("%s\n", stash);
		if (ft_strchr(stash, '\n'))
		{
			while (stash[len] != '\n')
				len++;
			line = ft_substr(stash, 0, len);
			tmp = ft_substr(stash, len, ft_strlen(stash));
			free(stash);
			stash = tmp;
			break ;
		}
		check = read(fd, buff, BUFFER_SIZE);
		printf("check: %d\n", check);
	}
	free(buff);
	return (line);
}

int	main(void)
{
	int		fd;
	char 	*line;

	fd = open("text4.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
	free(line);
}
