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

char    *get_next_line(int fd, size_t bs)
{
	static char    *to_read;
	static size_t	len_read = 0;
    char    *temp;
    size_t  bytes_read;
	if (!to_read)
		{
		to_read = (char *) malloc ((bs + 1) * sizeof(char));
		temp = "\0";
		}
	else if (!*to_read)
		return (NULL);
	else
		{
		to_read = to_read + len_read;
		temp = (char *) malloc ((ft_strlen_nl(to_read) + 1) * sizeof(char));
		ft_strcopy(temp, to_read);
		}
    bytes_read = 1;
	while (bytes_read != 0 && !find_nl(to_read))
	{
		to_read = (char *) malloc ((bs + 1) * sizeof(char));
        bytes_read = read(fd, to_read, bs);
		to_read[bytes_read] = '\0';
        temp = ft_makestr(temp, to_read);
    }
	len_read = ft_strlen_nl(to_read);
    return (temp);
}

#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*prt;
	fd = open("novo.txt", O_RDONLY);
	prt = get_next_line(fd, 1000);
	printf("\nFunc Return:%s", prt);
	free(prt);
	prt = get_next_line(fd, 1000);
	printf("\nFunc Return:%s", prt);
	free(prt);
	prt = get_next_line(fd, 1000);
	printf("\nFunc Return:%s", prt);
	free(prt);
	prt = get_next_line(fd, 1000);
	printf("\nFunc Return:%s", prt);
	free(prt);
	prt = get_next_line(fd, 1000);
	printf("\nFunc Return:%s", prt);
	free(prt);
	prt = get_next_line(fd, 1000);
	printf("\nFunc Return:%s", prt);
	free(prt);
	prt = get_next_line(fd, 1000);
	printf("\nFunc Return:%s", prt);
	free(prt);
	prt = get_next_line(fd, 1000);
	printf("\nFunc Return:%s\n", prt);
	free(prt);
	close(fd);
}

