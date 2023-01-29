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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	if (str[i] == '\n')
		i++;
	return (i);
}

void	ft_strcopy(char *dst, char *src)
{
	size_t	i;
	
	if(!*src)
		return ;
	i = 0;

	while (src[i]  && src[i] != '\n')
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

char	*ft_makestr(char *temp, char *to_read)
{
	char	*to_write;
	size_t len_temp;
	size_t len_read;
	size_t total;
	
	len_temp = ft_strlen(temp);
	len_read = ft_strlen(to_read);
	total = len_temp + len_read;
	//printf("total:%zu\n", total);	
	to_write = (char *) malloc((total + 1) * sizeof (char));
	ft_strcopy(to_write, temp);
	ft_strcopy((to_write + len_temp), to_read);
	/*if (*temp)
		free(temp);*/
	return(to_write);

}