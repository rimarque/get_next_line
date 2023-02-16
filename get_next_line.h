/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:49:10 by rimarque          #+#    #+#             */
/*   Updated: 2023/01/29 19:01:22 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

char	*get_next_line(int fd);
char	*free_str(int bytes, char *to_read, char *line);
char	*ft_strjoin(char *temp, char *to_read);
void	ft_strccpy(char *dst, char *src, char c);
size_t	ft_strclen(const char *str, char c);
int		find_nl(char *str);
char	*ft_calloc(size_t nmemb);

#endif