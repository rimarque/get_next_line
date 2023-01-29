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
		//printf("str: %s\n", str);
		if(str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char    *get_next_line(int fd, size_t bs)
{
        char    *to_read;
        char    *temp;
        size_t  bytes_read;
	
        to_read = (char *) malloc ((bs + 1) * sizeof(char));
	//to_read[0] = '\0';
        bytes_read = 1;
	//printf("bytes_read: %zu\n", bytes_read);
	//printf("to_read:%s\n", to_read);
	while (bytes_read != 0 && !find_nl(to_read))
	{
		//printf("bytes_read: %zu\n", bytes_read);
        	bytes_read = read(fd, to_read, bs);
		to_read[bytes_read] = '\0';
                temp = ft_makestr(temp, to_read);
        }
	//printf("temp:%s\n", temp);
	free(to_read);
        return (temp);
}

#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*prt;
	fd = open("novo.txt", O_RDONLY);
	prt = get_next_line(fd, 5);
	printf("\nFunc Return:%s\n", prt);
	free(prt);
	prt = get_next_line(fd, 5);
	printf("\nFunc Return:%s\n", prt);
	free(prt);
	prt = get_next_line(fd, 5);
	printf("\nFunc Return:%s\n", prt);
	free(prt);
	close(fd);
}

