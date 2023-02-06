/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:54:29 by rimarque          #+#    #+#             */
/*   Updated: 2023/01/29 19:56:39 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	temp = ft_calloc(ft_strlen_nl(to_read) + 1);
	//temp = (char *) malloc((ft_strlen_nl(to_read) + 1) * sizeof(char));
	ft_strcopy(temp, to_read);
	return (temp);
}
char    *get_next_line(int fd)
{
	static char    *to_read;
	static size_t	len_read = 0;
    char    *temp;
    size_t  bytes_read;
	//printf("\nto_read:%s", to_read);
	//printf("\nlen_read:%zu", len_read);
	temp = "\0";
	if (!to_read)
		to_read = ft_calloc(BUFFER_SIZE + 1);
	else
	{
		to_read = to_read + len_read;
		if (!*to_read)
			return (NULL);
		temp = make_temp(temp, to_read);
	}
    bytes_read = 1;
	while (bytes_read != 0 && !find_nl(to_read))
	{
		if (!*to_read)
			free(to_read);
		to_read = ft_calloc(BUFFER_SIZE + 1);
        bytes_read = read(fd, to_read, BUFFER_SIZE); 
        temp = ft_makestr(temp, to_read);
    }
	len_read = ft_strlen_nl(to_read);
	//printf("\nlast to_read:%s", to_read);
	//printf("\nlast to_read:%d", to_read[0]);
    return (temp);
}

/*#include <fcntl.h>
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
}*/

