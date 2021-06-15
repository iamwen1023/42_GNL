/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:51:59 by wlo               #+#    #+#             */
/*   Updated: 2021/05/28 14:53:38 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

size_t	ft_strlen( char *s);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char  *s, unsigned int start, size_t len);
size_t     ft_strlen_total(char *a);
char    *ft_strjoin(char *s1, char *s2);
void    new_buffer(char *s);
int     get_next_line(int fd, char **line);

#endif
