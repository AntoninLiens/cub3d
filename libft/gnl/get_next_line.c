/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:55:27 by aliens            #+#    #+#             */
/*   Updated: 2021/03/19 15:43:00 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_error(int fd, char **line)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE < 1 || !buf)
		return (0);
	return (buf);
}

int	ft_return(char **line, char *save, int reader, char **buf)
{
	free(*buf);
	if (!*line || (!save && reader))
	{
		free(*line);
		return (-1);
	}
	if (reader)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*save[OPEN_MAX];
	char		*buf;
	int			reader;

	buf = ft_error(fd, line);
	reader = 1;
	if (!buf)
		return (-1);
	while (!ft_end_line(save[fd]) && reader)
	{
		reader = (int)read(fd, buf, BUFFER_SIZE);
		if (reader < 0)
		{
			free(buf);
			return (-1);
		}
		buf[reader] = 0;
		save[fd] = ft_strjoin_gnl(save[fd], buf);
		if (!save[fd])
			return (-1);
	}
	*line = ft_line(save[fd]);
	save[fd] = ft_save(save[fd]);
	return (ft_return(line, save[fd], reader, &buf));
}
