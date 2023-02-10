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

int find_nl(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}
char *make_temp(char *temp, char *to_read)
{
	size_t len_temp;

	len_temp = ft_strclen(to_read, '\n');
	temp = ft_calloc(len_temp + 1);
	ft_strccpy(temp, to_read, '\n');
	if (to_read[len_temp] == '\0')
		free (to_read);
	return (temp);
}

char *move_to_read(char *to_read, size_t len)
{
	
	char *dst = ft_calloc((ft_strclen(to_read, '\0') + 1 )- len);
	ft_strccpy(dst, to_read + len, '\0');
	free(to_read);
	return(dst);
}
char *get_next_line(int fd)
{
	static char *to_read;
	size_t len_writen;
	char *temp;
	int bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = "\0";
	//printf("\nto_read 1:%s", to_read);
	//printf("\nto_read dec:%d", to_read[0]);
	if (!to_read)
		to_read = "\0";
	if (*to_read)
	{
		len_writen = ft_strclen(to_read, '\n');
		//printf("\nlen_written:%ld", len_writen);
		to_read = move_to_read(to_read, len_writen);
		//printf("\nto_read 2:%s", to_read);
		temp = make_temp(temp, to_read);
		//printf("\ntemp 1:%s", temp);
	}
	bytes_read = 1;
	if (!find_nl(to_read))
		to_read = ft_calloc(BUFFER_SIZE + 1);
	while (bytes_read > 0 && !find_nl(to_read))
	{
		bytes_read = read(fd, to_read, BUFFER_SIZE);
		if (bytes_read <= 0 && !*temp)
		{
		//free(temp);
		free(to_read);
		return (NULL);
		}
		if (bytes_read > 0)
			//printf("\nto_read 3:%s", to_read);
			temp = ft_strjoin(temp, to_read);
			//printf("\ntemp 2:%s", temp);
			//printf("\nto_read 4:%s", to_read);
	}
	return (temp);
}

#include <fcntl.h>
int main(void)
{
	int fd;
	char *prt;
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
	/*prt = get_next_line(fd);
	printf("\n7 Func Return:%s", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\n8 Func Return:%s", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\n9 Func Return:%s", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\n10 Func Return:%s", prt);
	free(prt);*/
	close(fd);
}