/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:21:57 by aliens            #+#    #+#             */
/*   Updated: 2021/04/12 15:21:21 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	square(t_params *vars, int x, int y, int s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < s)
	{
		j = -1;
		while (++j < s)
			put_pixel(vars, x * s + i, y * s + j, 100100100);
	}
}

void	display_map(t_map *map, t_params *vars)
{
	int	s;
	int	i;
	int	j;

	s = 0;
	i = -1;
	if (map->w_map > map->h_map)
		s = map->r1 / map->w_map;
	else
		s = map->r2 / map->h_map;
	printf("s = %d", s);
	while (++i < map->w_map)
	{
		j = -1;
		while (++j < map->h_map)
		{
			if (map->map[j][i] == 1)
				square(vars, i, j, s);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}