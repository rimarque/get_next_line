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
	char	*to_write;
	size_t len_temp;
	size_t len_read;
	size_t total;
	
	len_temp = ft_strclen(temp, '\n');
	len_read = ft_strclen(to_read, '\n');
	total = len_temp + len_read;
	//printf("\nlen_temp:%ld", len_temp);
	//printf("\nlen_read:%ld", len_read);
	//printf("\ntotal:%ld", total);
	to_write = ft_calloc(total + 1);
	ft_strccpy(to_write, temp, '\n');
	//printf("\nto_write 1:%s", to_write);
	ft_strccpy((to_write + len_temp), to_read, '\n');
	//printf("\nto_write 2:%s", to_write);
	//free(to_read);
	if (*temp)
		free(temp);
	return(to_write);
}