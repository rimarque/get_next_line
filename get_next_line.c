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

char	*move_to_read(char *to_read)
{
	size_t len;
	char *dst;

	len = ft_strclen(to_read, '\n');
	dst = ft_calloc((ft_strclen(to_read, '\0') + 1 ) - len);
	ft_strccpy(dst, to_read + len, '\0');
	free(to_read);
	return(dst);
}

char	*make_temp(char *temp, char **to_read)
{
	size_t len;

	len = ft_strclen(*to_read, '\n');
	if (len > 0)
	{
		temp = ft_calloc(len + 1);
		ft_strccpy(temp, *to_read, '\n');
	}
	if (to_read[0][len] == '\0')
	{
		free(*to_read);
		*to_read = NULL;
	}
	return (temp);
}

char *get_next_line(int fd)
{
	static char *to_read;
	char *temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = "\0";
	if (!to_read)
		to_read = "\0";
	if (*to_read)
	{
		to_read = move_to_read(to_read);
		temp = make_temp(temp, &to_read);
	}
	if (!find_nl(temp))
		temp = read_fd(fd, &to_read, temp);
	if (!temp)
		return (NULL);
	return (temp);
}

/*#include <fcntl.h>
int main(void)
{
	int fd;
	char *prt;
	fd = open("read_error.txt", O_RDONLY);
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
	printf("\n8 Func Return:%s", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\n9 Func Return:%s", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\n10 Func Return:%s", prt);
	free(prt);
	close(fd);
}*/