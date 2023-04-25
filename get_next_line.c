/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:54:29 by rimarque          #+#    #+#             */
/*   Updated: 2023/04/25 10:24:33 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	free_last_line(char	**str)
{
	if (*str == NULL)
		return ;
	if (count_nl(*str) == 1)
	{
		if (str[0][ft_strclen(*str, '\0') - 1] == '\n')
		{
			printf("entra aqui\n");
			ft_free(str);
		}
	}
}

char	*move_to_read(char **to_read)
{
	size_t	prev_line;
	char	*dst;

	prev_line = ft_strclen(*to_read, '\n');
	dst = ft_calloc((ft_strclen(*to_read, '\0') + 1) - prev_line, sizeof(char));
	ft_strccpy(dst, *to_read + prev_line, '\0');
	ft_free(to_read);
	return (dst);
}

char	*cpy_to_line(char *line, char **to_read)
{
	size_t	len;

	len = ft_strclen(*to_read, '\n');
	if (len > 0)
	{
		line = ft_calloc(len + 1, sizeof(char));
		ft_strccpy(line, *to_read, '\n');
	}
	if (to_read[0][len] == '\0')
		ft_free(to_read);
	return (line);
}

char	*read_to_line(int fd, char **to_read, char *line)
{
	int	bytes;

	bytes = 1;
	while (bytes > 0 && !count_nl(line))
	{
		if (bytes != 0)
		{
			ft_free(to_read);
			*to_read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		}
		bytes = read(fd, *to_read, BUFFER_SIZE);
		if (bytes <= 0)
			ft_free(to_read);
		if (bytes < 0 && *line)
			ft_free(&line);
		if (bytes < 0 || (bytes == 0 && !*line))
			return (NULL);
		if (bytes > 0)
			line = gft_strjoin(line, to_read);
	}
	free_last_line(to_read);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*to_read;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = "\0";
	if (!to_read)
		to_read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (*to_read)
	{
		to_read = move_to_read(&to_read);
		line = cpy_to_line(line, &to_read);
	}
	if (!count_nl(line))
		line = read_to_line(fd, &to_read, line);
	if (!line)
		return (NULL);
	return (line);
}

/*int	main()
{
	int		fd;
	char	*prt;
	int		i = 1;

	fd = open("test.txt", O_RDONLY);
	while (i <= 5)
	{
		prt = get_next_line(fd);
		//if (prt == NULL)
		//	break ;
		printf("%d: %s", i, prt);
		ft_free(&prt);
		i++;
	}
	close(fd);
	return(0);
}*/
