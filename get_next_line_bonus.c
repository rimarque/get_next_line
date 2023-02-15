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
	size_t	prev_line;
	char	*dst;

	prev_line = ft_strclen(to_read, '\n');
	dst = ft_calloc((ft_strclen(to_read, '\0') + 1) - prev_line);
	ft_strccpy(dst, to_read + prev_line, '\0');
	free(to_read);
	return (dst);
}

char	*cpy_to_line(char *line, char **to_read)
{
	size_t	len;

	len = ft_strclen(*to_read, '\n');
	if (len > 0)
	{
		line = ft_calloc(len + 1);
		ft_strccpy(line, *to_read, '\n');
	}
	if (to_read[0][len] == '\0')
	{
		free(*to_read);
		*to_read = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*to_read[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = "\0";
	if (!to_read[fd])
		to_read = "\0";
	if (*to_read[fd])
	{
		to_read[fd] = move_to_read(to_read[fd]);
		line = cpy_to_line(line, &to_read[fd]);
	}
	if (!find_nl(line))
		line = ft_get_line(fd, &to_read[fd], line);
	if (!line)
		return (NULL);
	return (line);
}

#include <fcntl.h>
int main(void)
{
	int fd_1;
	int fd_2;
	int fd_3;
	char *prt;

	fd_1 = open("multiple_nlx5", O_RDONLY);
	fd_2 = open("43_no_nl", O_RDONLY);
	fd_3 = open("alternate_line_nl_with_nl", O_RDONLY);
	printf("fd_1:%d\nfd_2:%d\nfd_3%d\n", fd_1, fd_2, fd_3);
	prt = get_next_line(fd_1);
	printf("\n1 Func Return:%s", prt);
	free(ptr);
	prt = get_next_line(fd_2);
	printf("\n1 Func Return:%s", prt);
	free (ptr);
	prt = get_next_line(fd_3);
	printf("\n1 Func Return:%s", prt);
	free(prt);
	/*prt = get_next_line(fd);
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
	free(prt);*/
	close(fd);
}