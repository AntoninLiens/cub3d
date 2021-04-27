/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:21:57 by aliens            #+#    #+#             */
/*   Updated: 2021/04/27 15:29:18 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_wall(t_map *map, int x, int y)
{
	if (map->map[y / map->wall_size][x / map->wall_size])
		return (1);
	return (0);
}

void	square(t_img *img, int x, int y, int s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < s)
	{
		j = -1;
		while (++j < s)
			put_pixel(img, x * s + i, y * s + j, 0xFFFFFF);
	}
}

void	display_map(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->map->w_map)
	{
		j = -1;
		while (++j < cub->map->h_map)
		{
			if (cub->map->map[j][i] == 1)
				square(cub->img, i, j, cub->map->wall_size);
		}
	}
	mlx_put_image_to_window(cub->vars->mlx, cub->vars->win, cub->img->img, 0, 0);
}