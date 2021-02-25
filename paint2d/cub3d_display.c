/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:21:19 by aliens            #+#    #+#             */
/*   Updated: 2021/02/25 14:01:05 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int		close_win(t_params *vars)
{
	(void)vars;
	exit(1);
	return (0);
}

void	player(t_params vars, int color)
{
	float	i;
	int		j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
			mlx_pixel_put(vars.mlx,\
			vars.win, vars.px + j - 5, vars.py + i - 5, color);
	}
	if (color)
		color = 150150150;
	i = -45;
	while (i <= 45)
	{
		i++;
		line(&vars, color, i);
	}
}

void	line(t_params *vars, int color, float j)
{
	float	dx;
	float	dy;
	int		i;

	i = -1;
	dx = cos(M_PI / 180 * (float)(vars->angle + j));
	dy = sin(M_PI / 180 * (float)(vars->angle + j));
	while (++i < 1111)
		mlx_pixel_put(vars->mlx,\
		vars->win, vars->px + (i * dx), vars->py - (i * dy), color);
}
