#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	char			*buff;
	int				fd;
	size_t		count;

	fd = open("text4.txt", O_RDONLY);
	count = 100;
	buff = malloc(sizeof(char) * count + 1);
	read(fd, buff, count);
	buff[count] = '\0';
	printf("%s\n", buff);
	free(buff);
	close(fd);
}

/*o que eu preciso fazer:
 *-alocar buffer_size + 1
 *checar o retorno de read:
 *se read for maior que 0:
 *	adicionar '\0' no final
 *	concatenar (ou dar join) com o stash
 *	checar se o stash está com o \n
 *	se estiver:
 *	separar, retornar tudo antes de \n e guardar o resto em stash
 *se read for igual a 0:
 *	dar free em buff
 *	e retornar stash
 *se read for menor que 0:
 *	dar free em buff e stash e retornar null
 */
