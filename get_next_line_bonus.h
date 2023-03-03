/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:43:29 by rimarque          #+#    #+#             */
/*   Updated: 2023/02/16 16:43:35 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef SOFT_LIMIT
#  define SOFT_LIMIT 1024
# endif

char	*get_next_line(int fd);
char	*free_str(int bytes, char *to_read, char *line);
char	*ft_strjoin(char *temp, char *to_read);
void	ft_strccpy(char *dst, char *src, char c);
size_t	ft_strclen(const char *str, char c);
int		find_nl(char *str);
char	*ft_calloc(size_t nmemb);

#endif
