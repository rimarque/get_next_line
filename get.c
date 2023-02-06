#include "get_next_line.h"

int	find_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if(str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
char	*make_temp(char *temp, char *to_read)
{
	temp = (char *) malloc(( ft_strlen_nl(to_read) + 1) * sizeof (char));
	//temp = ft_calloc(ft_strlen_nl(to_read) + 1);
	ft_strcopy(temp, to_read);
	return (temp);
}
char    *get_next_line(int fd)
{
	static char    *to_read;
	static size_t	len_read = 0;
    char    *temp;
    size_t  bytes_read;
	printf("to_read:%s", to_read);
	temp = "\0";
	if (!to_read)
	{
		//printf("passou if(!to_read");
		//to_read = ft_calloc(BUFFER_SIZE + 1);
		to_read = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	}
	else if (!*to_read)
	{
		//printf("passou if(!*to_read");
		return (NULL);
	}
	else
	{
		//printf("passou else");
		to_read = to_read + len_read;
		temp = make_temp(temp, to_read);
		printf("passou l 56");
	}
	//printf("passou l 61");
    bytes_read = 1;
	while (bytes_read != 0 && !find_nl(to_read))
	{
		free(to_read);
		/*if (?)
			to_read = ft_calloc(len_read + 1);*/
		to_read = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char)); //memory leek alocar memoria à ultima leitura
        bytes_read = read(fd, to_read, BUFFER_SIZE);
		to_read[bytes_read] = '\0';
		printf("\nbytes_read:%zu", bytes_read);
        temp = ft_makestr(temp, to_read);
		printf("entrou loop");
    }
	len_read = ft_strlen_nl(to_read);
	printf("\nlen_read:%zu", len_read);
	printf("\nlast to_read:%s", to_read);
    return (temp);
}

#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*prt;
	fd = open("novo.txt", O_RDONLY);
	prt = get_next_line(fd);
	printf("\n1 Func Return:%s", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\n2 Func Return:%s", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\n3 Func Return:%s", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\n4 Func Return:%s", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\n5 Func Return:%s", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\n6 Func Return:%s", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\n7 Func Return:%s", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\n8 Func Return:%s\n", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\n9 Func Return:%s\n", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\n10 Func Return:%s\n", prt);
	free(prt);
	close(fd);
}