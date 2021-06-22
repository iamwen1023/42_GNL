/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:51:19 by wlo               #+#    #+#             */
/*   Updated: 2021/06/22 14:13:55 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen_total(char *a)
{
	int	length;

	length = 0;
	if (!a)
		return (0);
	while (*a != '\0' && *a != '\n')
	{
		length++;
		a++;
	}
	return (length);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	arr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!arr)
		return (0);
	i = 0;
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		arr[i + j] = s2[j];
		j++;
	}
	arr[i + j] = '\0';
	free(s1);
	return (arr);
}

void	new_buffer(char *s)
{
	size_t	i;
	char	*c;

	i = 0;
	c = ft_strchr(s, '\n');
	if (!c)
		return ;
	if (c == &s[ft_strlen(s) - 1])
	{
		s[0] = '\0';
		return ;
	}
	c++;
	while (c[i])
	{
		s[i] = c[i];
		i++;
	}
	s[i] = '\0';
}

int	read_file(char **arr, int fd, char *buffer)
{
	int	ret;

	ret = 0;
	while (ft_strchr(*arr, '\n') == 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
			return (-1);
		buffer[ret] = '\0';
		if (ret == 0)
			break ;
		if (!*arr)
			*arr = ft_substr(buffer, 0, (size_t)ret);
		else
			*arr = ft_strjoin(*arr, buffer);
	}
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*arr;
	int			ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	arr = NULL;
	if (buffer[0])
		arr = ft_substr(buffer, 0, ft_strlen_total(buffer) + 1);
	ret = read_file(&arr, fd, buffer);
	if (ret < -1)
		return (-1);
	*line = ft_substr(arr, 0, ft_strlen_total(arr));
	free(arr);
	if (!line[0])
		*line = ft_substr("\0", 0, 1);
	if (!buffer[0] && ret == 0)
		return (0);
	new_buffer(buffer);
	return (1);
}
