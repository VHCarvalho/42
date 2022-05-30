/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vh.crvlh@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:46:08 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/30 19:06:34 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
/*get_next_line:
 *alocar buffer_size + 1
 *checar o retorno de read
 *se for maior que 0:
 *	adicionar '\0' no final
 *	concatenar com o stash
 *	checar se o stash está com \n
 *	se estiver:
 *	separar, retornar tudo antes de \n e guardar o resto em stash
 *se read for igual a 0:
 *	dar free em buff e retornar stash
 *	se read for menor que 0:
 *	dar free em buff e stash e retornar null;
 */

static char	*store_buffer(char *buff, char *stash)
{
	size_t	i;
	char	*str;

	if (!buff)
		return (NULL);
	i = 0;
	if (!stash)
	{
		str = malloc(sizeof(char) * ft_strlen(buff) + 1);
		while (buff[i])
		{
			str[i] = buff[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	str = ft_strjoin(stash, buff);
	free(stash);
	return (str);
}

static char	*get_line(char *stash, char *line)
{
	size_t	i;
	size_t	len;

	if (!stash)
		return (NULL);
	len = 0;
	while (stash[len] != '\n')
		len++;
	line = malloc(sizeof(char) * len + 2);
	i = 0;
	while (stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

static char	*stash_leftovers(char *stash)
{
	size_t	i;
	size_t	j;
	size_t	new_len;
	char	*str;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] != '\n')
		i++;
	i++;
	j = i;
	while (stash[i])
	{
		new_len++;
		i++;
	}
	if (new_len == 0)
	{
		free(stash);
		return (NULL);
	}
	str = malloc(sizeof(char) * new_len + 1);
	i = 0;
	while (stash[j])
		str[i++] = stash[j++];
	str[i] = '\0';
	free(stash);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buff;
	char		*line;
	int			bytes;

	if (fd < 0)
		return (NULL);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	line = NULL;
	bytes = read(fd, buff, BUFFER_SIZE);
	while (bytes > 0)
	{
		buff[bytes] = '\0';
		stash = store_buffer(buff, stash);
		if (ft_strchr(stash, '\n'))
		{
			line = get_line(stash, line);
			stash = stash_leftovers(stash);
			free(buff);
			return (line);
		}
		bytes = read(fd, buff, BUFFER_SIZE);
	}
	if (bytes == 0)
	{
		free(buff);
		return (stash);
	}
	free(buff);
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text1.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
