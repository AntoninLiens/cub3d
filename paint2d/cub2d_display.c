/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:21:19 by aliens            #+#    #+#             */
/*   Updated: 2021/04/16 13:50:00 by aliens           ###   ########.fr       */
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
	float	i;
	int		j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
			put_pixel(cub->img, cub->vars->px + j - 5, cub->vars->py + i - 5, color);
	}
	if (color)
		color = 150150150;
	i = -30;
	while (i <= 30)
	{
		i++;
		line(cub, color, i);
	}
	mlx_put_image_to_window(cub->vars->mlx, cub->vars->win, cub->img->img, 0, 0);
}

void	line(t_cub *cub, int color, float j)
{
	float	dx;
	float	dy;
	int		i;

	i = -1;
	dx = 0;
	dy = 0;
	while (++i < 500 && !is_wall(cub->map, cub->vars->px + (i * dx), cub->vars->py - (i * dy)))
	{
		dx = cos(M_PI / 180 * (float)(cub->vars->angle + j));
		dy = sin(M_PI / 180 * (float)(cub->vars->angle + j));
		put_pixel(cub->img, cub->vars->px + (i * dx), cub->vars->py - (i * dy), color);
	}
}
