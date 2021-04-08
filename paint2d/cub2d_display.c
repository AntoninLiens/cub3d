/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:21:19 by aliens            #+#    #+#             */
/*   Updated: 2021/04/08 14:21:09 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	close_win(t_params *vars)
{
	(void)vars;
	exit(1);
	return (0);
}

void	put_pixel(t_params *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->ll + x * (vars->bpp / 8));
	*(unsigned int *)dst = color;
}

void	player(t_params *vars, int color)
{
	float	i;
	int		j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
			put_pixel(vars, vars->px + j - 5, vars->py + i - 5, color);
	}
	if (color)
		color = 150150150;
	i = -30;
	while (i <= 30)
	{
		i++;
		line(vars, color, i);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

void	line(t_params *vars, int color, float j)
{
	float	dx;
	float	dy;
	int		i;

	i = -1;
	dx = cos(M_PI / 180 * (float)(vars->angle + j));
	dy = sin(M_PI / 180 * (float)(vars->angle + j));
	while (++i < 500)
		put_pixel(vars, vars->px + (i * dx), vars->py - (i * dy), color);
}
