/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:21:19 by aliens            #+#    #+#             */
/*   Updated: 2021/05/06 15:47:56 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	close_win(t_param *vars)
{
	(void)vars;
	exit(1);
	return (0);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	player(t_cub *cub, int color)
{
	double	i;
	int		j;

	i = -1;
	while (++i < cub->map->wall_size / 4)
	{
		j = -1;
		while (++j < cub->map->wall_size / 4)
			put_pixel(cub->img, cub->map->wall_size * cub->vars->px + j - cub->map->wall_size / 8,
			 cub->map->wall_size * cub->vars->py + i - cub->map->wall_size / 8, color);
	}
	if (color)
		color = 150150150;
	line(cub, color, 0);
	mlx_put_image_to_window(cub->vars->mlx, cub->vars->win, cub->img->img, 0, 0);
}

void	line(t_cub *cub, int color, double j)
{
	double	dx;
	double	dy;
	double	distx;
	double	disty;
	double	nextx;
	double	nexty;
	double	dist_to_wall;
	int		i;
	int		stepx;
	int		stepy;
	int		side;
	int		mapx;
	int		mapy;
	int		hit;

	i = -1;
	hit = 0;
	dx = cos(((M_PI / 180)) * (double)(cub->vars->angle + j));
	dy = sin(((M_PI / 180)) * (double)(cub->vars->angle + j));
	mapx = (int)cub->vars->px;
	mapy = (int)cub->vars->py;
	if ((int)dy == 0)
		distx = 0;
	else
	{
		if ((int)dx == 0)
			distx = 1;
		else
			distx = fabs(1 / dx);
	}
	if ((int)dx == 0)
		disty = 0;
	else
	{
		if ((int)dy == 0)
			disty = 1;
		else
			disty = fabs(1 / dy);
	}
	printf("dx = %f, dy = %f\n", dx, dy);
	printf("distx = %f, disty = %f\n", distx, disty);
	if (dx < 0)
	{
		stepx = -1;
		nextx = (cub->vars->px - mapx) * distx;
	}
	else
	{
		stepx = 1;
		nextx = (mapx + 1.0 - cub->vars->px) * distx;
	}
	if (dy < 0)
	{
		stepy = -1;
		nexty = (cub->vars->py - mapy) * disty;
	}
	else
	{
		stepy = 1;
		nexty = (mapy + 1.0 - cub->vars->py) * disty;
	}
	while (hit == 0)
	{
		if (nexty < nextx)
		{
			nextx += dx;
			mapx += stepx;
			side = 1;
		}
		else
		{
			nexty += dy;
			mapy += stepy;
			side = 0;
		}
		if (cub->map->map[mapy][mapx] > 0)
			hit = 1;
	}
	if (side == 0)
		dist_to_wall = fabs((cub->vars->px - mapx + (1 - stepx) / 2) / dx);
	else
		dist_to_wall = fabs((cub->vars->py - mapy + (1 - stepy) / 2) / dy);
	printf("dist_to_wall = %f\n", dist_to_wall);
	while (++i < dist_to_wall * cub->map->wall_size)
		put_pixel(cub->img, cub->map->wall_size * cub->vars->px + i * dx, cub->map->wall_size * cub->vars->py - i * dy, color);
}
