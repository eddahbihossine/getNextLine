/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 02:44:18 by heddahbi          #+#    #+#             */
/*   Updated: 2022/11/18 02:44:23 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (free((void *)s1), str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if ((ft_strlen(s + start)) < len)
		len = ft_strlen(s + start);
	p = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!p)
		return (free(p), NULL);
	while (i < len)
	{
		p[i] = *(s + start + i);
		i++;
	}
	p[i] = '\0';
	return (p);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	size_t	len;
	char	*p;

	i = 0;
	len = ft_strlen(src);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (free(p), NULL);
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;
	void			*k;
	int				n;

	n = sizeof(p);
	k = malloc(size * count);
	if (!k)
		return (free(k), NULL);
	if (count * size > SIZE_MAX && size)
		return (NULL);
	p = k;
	while (*p && (*p < n))
	{
		*p = 0;
		p++;
	}
	return ((void *)p);
}
