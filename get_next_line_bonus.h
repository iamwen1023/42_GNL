/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:51:59 by wlo               #+#    #+#             */
/*   Updated: 2021/06/24 15:43:09 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 64
# endif

size_t	ft_strlen( char *s);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen_total(char *a);
char	*ft_strjoin(char *s1, char *s2);
char	*new_buffer(char *rest, char *buffer, int ret);
int		read_file(char **arr, int fd, char *buffer);
int		get_next_line(int fd, char **line);

#endif
