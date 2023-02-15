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

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10

# endif

char    *ft_strjoin(char *temp, char *to_read);
char    *get_next_line(int fd);
size_t	ft_strclen(const char *str, char c);
void	ft_strccpy(char *dst, char *src, char c);
char	*ft_calloc(size_t nmemb);
char	*read_fd(int fd, char **to_read, char *temp);
int     find_nl(char *str);

# endif

