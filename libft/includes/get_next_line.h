/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:55:52 by aliens            #+#    #+#             */
/*   Updated: 2021/03/19 15:41:56 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../includes/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

# define BUFFER_SIZE 10

int		get_next_line(int fd, char **line);
int		ft_end_line(char *str);
int		ft_return(char **line, char *save,
			int reader, char **buf);
char	*ft_save(const char *str);
char	*ft_line(char *str);
char	*ft_error(int fd, char **line);
char	*ft_strjoin_gnl(char const *s1, char const *s2);

#endif
