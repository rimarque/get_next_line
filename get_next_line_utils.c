/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:17:42 by rimarque          #+#    #+#             */
/*   Updated: 2023/01/29 19:58:25 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_calloc(size_t n)
{
	char	*dst;

	dst = (char *) malloc(n);
	if (!dst)
		return (0);
	while (n)
			dst[--n] = '\0';
	return (dst);
}

size_t	ft_strclen(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
	}
	if (str[i] == '\n')
		i++;
	return (i);
}

void	ft_strccpy(char *dst, char *src, char c)
{
	size_t	i;
	
	if(!*src)
		return ;
	i = 0;
	while (src[i] && src[i] != c)
	{
		dst[i] = src[i];
		i++;	
	}
	if (src[i] == '\n')
	{
		dst[i] = '\n';
		i++;
	}	
	dst[i] = '\0';
}

char	*ft_strjoin(char *temp, char *to_read)
{
	char	*dst;
	size_t len_temp;
	size_t len_read;
	
	len_temp = ft_strclen(temp, '\n');
	len_read = ft_strclen(to_read, '\n');
	dst = ft_calloc(len_temp + len_read + 1);
	ft_strccpy(dst, temp, '\n');
	ft_strccpy((dst + len_temp), to_read, '\n');
	if (*temp)
		free(temp);
	return(dst);
}

char	*read_fd(int fd, char **to_read, char *temp)
{	
	int bytes;

	bytes = 1;
	*to_read = ft_calloc(BUFFER_SIZE + 1);
	while (bytes > 0 && !find_nl(temp))
	{
		if (bytes != 0)
		{
			free(*to_read);
			*to_read = ft_calloc(BUFFER_SIZE + 1);
		}
		bytes = read(fd, *to_read, BUFFER_SIZE);
		if(bytes <= 0)
		{
			free(*to_read);
			*to_read = NULL;
		}
		if (bytes < 0 || (bytes == 0 && !*temp))
			return (NULL);
		if (bytes > 0)
			temp = ft_strjoin(temp, *to_read);
	}
	return (temp);
}