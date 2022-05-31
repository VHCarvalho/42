/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vh.crvlh@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:46:08 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/05/31 17:22:07 by vcarvalh         ###   ########.fr       */
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
	size_t	i_stash;
	size_t	i_buff;
	char	*str;

	if (!stash)
	{
		stash = malloc(sizeof(char));
		stash[0] = '\0';
	}
	if (!buff || !stash)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(stash) + 1));
	if (!str)
		return (NULL);
	i_stash = -1;
	if (stash)
		while (stash[++i_stash])
			str[i_stash] = stash[i_stash];
	i_buff = 0;
	while (buff[i_buff])
		str[i_stash++] = buff[i_buff++];
	str[ft_strlen(buff) + ft_strlen(stash)] = '\0';
	free(stash);
	return (str);
}

static char	*get_line(char *stash)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		str[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		str[i] = stash[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*stash_leftovers(char *stash)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!str)
		return (NULL);
	j = 0;
	i++;
	while (stash[i])
		str[j++] = stash[i++];
	str[j] = '\0';
	free(stash);
	return (str);
}
char	*read_buffer(int fd, char *stash)
{
	char	*buff;
	int		bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		stash = store_buffer(buff, stash);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stash = read_buffer(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = stash_leftovers(stash);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text4.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}*/
