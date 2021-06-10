/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:51:19 by wlo               #+#    #+#             */
/*   Updated: 2021/05/28 14:51:33 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

#define BUFFER_SIZE 5

size_t     ft_strlen_total(char *a)
{       
        int     length;
        
        length = 0;
        while (*a != '\0' && *a !='\n')
        {       
                length++;
                a++;
        }
        return (length);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *arr;
    size_t    i;
    size_t    j;

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
    //free(s1);
    return (arr);
}

void    new_buffer(char *s)
{
    size_t  i;
    char    *c;

    c = ft_strchr(s , '\n');
    if (!c)
        return;
    c++;
    i = 0;
    while (c[i])
    {
        s[i] = c[i];
        i++;
    }
    s[i] = '\0';
}

int get_next_line(int fd, char **line)
{
    static char buffer[BUFFER_SIZE + 1];
    char        *arr = 0;
    int         ret;

    if (fd <= 0 || line == 0)
        return (-1);
    if (buffer[0])
        arr = ft_substr(buffer, 0, ft_strlen_total(buffer) + 1);
    printf("arr: %s\n", arr);
    while (ft_strchr(arr, '\n') == 0)
    {
        ret = read(fd, buffer, BUFFER_SIZE);
        if (ret < 0)
            return (-1);
        if (ret == 0)
            return (0);
        buffer[ret] = '\0';
        if (!arr)
            arr = ft_substr(buffer, 0, (size_t)ret);
        else
            arr = ft_strjoin(arr, buffer);
        printf("arr in the loop: %s\n", arr);
    }
    printf("Len of total: %zu\n", ft_strlen_total(arr));
    *line = ft_substr(arr, 0, ft_strlen_total(arr));
    printf("line: %s\n", *line);
    new_buffer(buffer);
    free(arr);
    return (1);
}

int main()
{
    int     fd;
	char	**line;
	int     i;

	fd = open("try", O_RDONLY);

    // while (get_next_line(fd, line) > 0)
	// {
	// 	printf("line %s\n", line[0]);
	// }
   

	 i = get_next_line(fd, line);
     printf("line %s\n", line[0]);
    //  i = get_next_line(fd, line);
    //  //printf("22line %s\n", line[0]);
    //  i = get_next_line(fd, line);
    //  //printf("line %s\n", line[0]);
    //  i = get_next_line(fd, line);
     //printf("line %s\n", line[0]);
    //  i = get_next_line(fd, line);
    //  printf("line %s\n", line[0]);
    //  i = get_next_line(fd, line);
     //printf("line %s\n", line[0]);
	//i = get_next_line(fd, line);
	close(fd);
    return 0;
}