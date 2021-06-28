/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:14:06 by wlo               #+#    #+#             */
/*   Updated: 2021/06/28 14:40:12 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*new_buffer(char *rest, char *buffer, int ret)
{
	char	*next_rest;

	next_rest = ft_strchr(rest, '\n');
	if (!next_rest)
	{
		free(rest);
		next_rest = ft_substr(buffer, ft_strlen_total(buffer) + 1, ret);
		if (ft_strlen(next_rest) == 0)
		{
			free(next_rest);
			return (NULL);
		}
		return (next_rest);
	}
	if (next_rest == &rest[ft_strlen(rest) - 1])
	{
		free(rest);
		return (NULL);
	}
	next_rest = ft_substr(rest, ft_strlen_total(rest) + 1, ft_strlen(rest));
	free(rest);
	return (next_rest);
}

int	read_file(char **arr, int fd, char *buffer)
{
	int	ret;

	ret = 1;
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
	char		buffer[BUFFER_SIZE + 1];
	static char	*rest[OPEN_MAX];
	char		*arr;
	int			ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (-1);
	arr = NULL;
	if (rest[fd])
		arr = ft_substr(rest[fd], 0, ft_strlen(rest[fd]));
	ret = read_file(&arr, fd, buffer);
	if (ret == -1)
		return (-1);
	*line = ft_substr(arr, 0, ft_strlen_total(arr));
	free(arr);
	if (*line == 0)
		*line = ft_substr("\0", 0, 1);
	rest[fd] = new_buffer(rest[fd], buffer, ret);
	if (ret == 0 && rest[fd] == NULL)
		return (0);
	return (1);
}
