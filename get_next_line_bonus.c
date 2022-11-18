/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:27:56 by heddahbi          #+#    #+#             */
/*   Updated: 2022/11/18 00:48:54 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*f[OPEN_MAX];
	char		*line;
	int			to_read;
	int			i;

	if (!f[fd])
		f[fd] = ft_strdup("");
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	to_read = read(fd, buffer, BUFFER_SIZE);
	while (to_read >= 0)
	{
		if ((!f[fd][0] && !to_read) || to_read == -1)
			break ;
		buffer[to_read] = '\0';
		f[fd] = ft_strjoin(f[fd], buffer);
		i = check_the_n(f[fd]);
		if (i != -1)
			return (free(buffer), ft_line(&f[fd], &line, i));
		if (!to_read)
			return (free(buffer), rest(&f[fd], 0));
		to_read = read (fd, buffer, BUFFER_SIZE);
	}
	return (free(buffer), free(f[fd]), f[fd] = NULL, NULL);
}

char	*rest(char **f, int i)
{
	int		length;
	char	*k;

	length = ft_strlen(*f + i);
	k = ft_substr(*f, i, length);
	free(*f);
	*f = NULL;
	return (k);
}

char	*ft_line(char **f, char **line, int i)
{
	*line = ft_substr(*f, 0, i + 1);
	*f = rest(f, i + 1);
	return (*line);
}

int	check_the_n(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
