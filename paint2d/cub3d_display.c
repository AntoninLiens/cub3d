/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:21:19 by aliens            #+#    #+#             */
/*   Updated: 2021/02/17 16:56:28 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    player(t_params vars, int color)
{
    float   i;
    int     j;

    i = -1;
    while (++i < 10)
    {
        j = -1;
        while (++j < 10)
            mlx_pixel_put(vars.mlx, vars.win, vars.p_x + j - 5, vars.p_y + i - 5, color);
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

void    line(t_params *vars, int color, float j)
{
    float   d_x;
    float   d_y;
    int     i;

    i = -1;
    d_x = cos(M_PI / 180 * (float)(vars->angle + j));
    d_y = sin(M_PI / 180 * (float)(vars->angle + j));
    while (++i < 1111)
        mlx_pixel_put(vars->mlx, vars->win, vars->p_x + (i * d_x), vars->p_y - (i * d_y), color);
}