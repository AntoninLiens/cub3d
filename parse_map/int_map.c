/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:35:03 by aliens            #+#    #+#             */
/*   Updated: 2021/04/07 17:05:55 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_int_map(t_list *charmap, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	map->h_map = ft_lstsize(charmap);
	map->map = (int **)malloc(sizeof(int *) * map->h_map);
	if (!map->map)
		return ;
	while (++i < map->h_map)
	{
		map->map[i] = int_line(charmap, map);
		charmap = charmap->next;
	}
	i = -1;
	while (++i < map->h_map)
	{
		j = -1;
		while (map->map[i][++j] != -48)
			printf("%d", map->map[i][j]);
		printf("\n");
	}
	printf("w_map : %d\n", map->w_map);
	printf("h_map : %d\n", map->h_map);
}

int	*int_line(t_list *charmap, t_map *map)
{
	int		i;
	char	*str;
	int		*map_line;

	i = ft_strlen(charmap->content) + 1;
	if (i > map->w_map)
		map->w_map = i;
	map->map = (int **)malloc(sizeof(int *) * map->h_map);
	if (!map_line)
		return (0);
	str = charmap->content;
	while (i--)
		map_line[i] = (int)str[i] - '0';
	return (map_line);
}
