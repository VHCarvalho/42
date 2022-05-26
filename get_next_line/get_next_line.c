/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:32:20 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/26 09:54:04 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

/*char	*get_next_line(int fd)
{

}*/

int	main(void)
{
	int		fd;
	char 	*line;
	size_t	count;
	int		check;

	count = 5;
	line = malloc(sizeof(char) * count + 1);
	fd = open("text4.txt", O_RDONLY);
	check = 0;
	while ((read(fd, line, count)) > 0)
	{
		if (check > 0)
			line = malloc(sizeof(char) * count + 1);
		read(fd, line, count);
		line[count] = '\0';
		printf("%s\n", line);
		free(line);
		check++;
	}
}
