/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:21:57 by aliens            #+#    #+#             */
/*   Updated: 2021/05/03 13:29:57 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	wall(t_cub *cub, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (++i < cub->map->wall_size - 1)
	{
		j = 0;
		while (++j < cub->map->wall_size - 1)
			put_pixel(cub->img, x * cub->map->wall_size + i,
			y * cub->map->wall_size + j, color);
	}
}

void	display_map(t_cub *cub, int color)
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
				wall(cub, i, j, color);
		}
	}
	player(cub, 100100100);
	mlx_put_image_to_window(cub->vars->mlx, cub->vars->win, cub->img->img, 0, 0);
}