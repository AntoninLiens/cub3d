/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 12:24:03 by aliens            #+#    #+#             */
/*   Updated: 2021/02/17 13:32:24 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 10

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
int		ft_end_line(char *str);
char	*ft_save(const char *str);
char	*ft_line(char *str);
char	*ft_error(int fd, char **line);

size_t	ft_strlen_gnl(const char *a);
void	*ft_memcpy_gnl(void *dst, const void *src, size_t n);
void	*ft_calloc_gnl(size_t count, size_t size);
char	*ft_strdup_gnl(const char *s1);
char	*ft_strjoin_gnl(char const *s1, char const *s2);

#endif
