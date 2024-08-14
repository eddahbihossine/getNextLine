/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 02:50:44 by heddahbi          #+#    #+#             */
/*   Updated: 2022/11/18 02:56:53 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

char	*ft_strjoin(char const	*s1, char const	*s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_line(char	**f, char	**line, int i);
char	*rest(char	**f, int i);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
int		check_the_n(char	*buffer);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

#endif