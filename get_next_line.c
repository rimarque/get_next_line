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

char	*read_to_line(int fd, char **to_read, char *line)
{	
	int	bytes;

	bytes = 1;
	while (bytes > 0 && !find_nl(line))
	{
		if (bytes != 0)
		{
			free(*to_read);
			*to_read = ft_calloc(BUFFER_SIZE + 1);
		}
		bytes = read(fd, *to_read, BUFFER_SIZE);
		if (bytes <= 0)
		{
			free(*to_read);
			*to_read = NULL;
		}
		if (bytes < 0 && *line)
			free(line);
		if (bytes < 0 || (bytes == 0 && !*line))
			return (NULL);
		if (bytes > 0)
			line = ft_strjoin(line, *to_read);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*to_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = "\0";
	if (!to_read)
		to_read = ft_calloc(BUFFER_SIZE + 1);
	if (*to_read)
	{
		to_read = move_to_read(to_read);
		line = cpy_to_line(line, &to_read);
	}
	if (!find_nl(line))
		line = read_to_line(fd, &to_read, line);
	if (!line)
		return (NULL);
	return (line);
}
