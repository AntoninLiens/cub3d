/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:44:23 by aliens            #+#    #+#             */
/*   Updated: 2021/02/21 13:32:59 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		get_infos_map(char *line, t_map *map)
{
	int i;

	i = 0;
	if (line[0] == 'R' && ++i)
		get_r(line, map);
	else if (line[0] == 'F' && ++i)
		get_f(line, map);
	else if (line[0] == 'C' && ++i)
		get_c(line, map);
	else if (line[0] == 'N' && line[1] == 'O' && ++i)
		map->no = get_textures(line, 2);
	else if (line[0] == 'S' && line[1] == 'O' && ++i)
		map->so = get_textures(line, 2);
	else if (line[0] == 'W' && line[1] == 'E' && ++i)
		map->we = get_textures(line, 2);
	else if (line[0] == 'E' && line[1] == 'A' && ++i)
		map->ea = get_textures(line, 2);
	else if (line[0] == 'S' && ++i)
		map->s = get_textures(line, 1);
	return (i);
}

void	get_r(char *line, t_map *map)
{
	char	**str;

	str = ft_split(line, ' ');
	map->r1 = ft_atoi(str[1]);
	map->r2 = ft_atoi(str[2]);
}

void	get_f(char *line, t_map *map)
{
	char	**str;

	str = ft_split(line + 1, ',');
	map->f = create_rgb(ft_atoi(str[0]), ft_atoi(str[1]), ft_atoi(str[2]));
}

void	get_c(char *line, t_map *map)
{
	char	**str;

	str = ft_split(line + 1, ',');
	map->c = create_rgb(ft_atoi(str[0]), ft_atoi(str[1]), ft_atoi(str[2]));
}

char	*get_textures(char *line, int i)
{
	int		j;

	j = ft_strlen(line);
	while (line[i] == ' ')
		i++;
	while (line[j] == ' ')
		j--;
	return (ft_substr(line, (unsigned int)i, (size_t)j));
}
