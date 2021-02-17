/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:44:23 by aliens            #+#    #+#             */
/*   Updated: 2021/02/17 17:23:10 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void    get_R(char *line, t_map *map)
{
    char    **str;

    str = ft_split(line, ' ');
    map->R1 = ft_atoi(str[1]);
    map->R2 = ft_atoi(str[2]);
}

void    get_F(char *line, t_map *map)
{
    char    **str;

    str = ft_split(line + 1, ',');
    map->F = create_rgb(ft_atoi(str[0]), ft_atoi(str[1]), ft_atoi(str[2]));
}

void    get_C(char *line, t_map *map)
{
    char    **str;

    str = ft_split(line + 1, ',');
    map->C = create_rgb(ft_atoi(str[0]), ft_atoi(str[1]), ft_atoi(str[2]));
}

char    *get_textures(char *line, int i)
{
    int     j;

    j = ft_strlen(line);
    while (line[i] == ' ')
        i++;
    while (line[j] == ' ')
        j--;
    return (ft_substr(line, (unsigned int)i, (size_t)j));
}