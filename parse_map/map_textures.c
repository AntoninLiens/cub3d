/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:30:05 by aliens            #+#    #+#             */
/*   Updated: 2021/02/17 13:04:27 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char    *get_NO(char *line)
{
    int     i;
    int     j;

    i = 0;
    j = ft_strlen(line);
    if (line[i] == 'N')
        i++;
    if (line[i] == 'O')
        i++;
    while (line[i] == ' ')
        i++;
    while (line[j] == ' ')
        j--;
    return (ft_substr(line, (unsigned int)i, (size_t)j));
}

char    *get_SO(char *line)
{
    int     i;
    int     j;

    i = 0;
    j = ft_strlen(line);
    if (line[i] == 'S')
        i++;
    if (line[i] == 'O')
        i++;
    while (line[i] == ' ')
        i++;
    while (line[j] == ' ')
        j--;
    return (ft_substr(line, (unsigned int)i, (size_t)j));
}

char    *get_WE(char *line)
{
    int     i;
    int     j;

    i = 0;
    j = ft_strlen(line);
    if (line[i] == 'W')
        i++;
    if (line[i] == 'E')
        i++;
    while (line[i] == ' ')
        i++;
    while (line[j] == ' ')
        j--;
    return (ft_substr(line, (unsigned int)i, (size_t)j));
}

char    *get_EA(char *line)
{
    int     i;
    int     j;

    i = 0;
    j = ft_strlen(line);
    if (line[i] == 'E')
        i++;
    if (line[i] == 'A')
        i++;
    while (line[i] == ' ')
        i++;
    while (line[j] == ' ')
        j--;
    return (ft_substr(line, (unsigned int)i, (size_t)j));
}

char    *get_S(char *line)
{
    int     i;
    int     j;

    i = 0;
    j = ft_strlen(line);
    while (line[i] == ' ')
        i++;
    if (line[i] == 'S')
        i++;
    while (line[i] == ' ')
        i++;
    while (line[j] == ' ')
        j--;
    return (ft_substr(line, (unsigned int)i, (size_t)j));
}