/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:21:19 by aliens            #+#    #+#             */
/*   Updated: 2021/02/11 16:59:03 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    player(t_params vars, int color)
{
    int i;
    int j;

    i = -1;
    while (++i < 10)
    {
        j = -1;
        while (++j < 10)
            mlx_pixel_put(vars.mlx, vars.win, vars.p_x + j, vars.p_y + i, color);
    }
    if (color)
        color = 150150150;
    line(&vars, color);
}

void    line(t_params *vars, int color)
{
    float   d_x;
    float   d_y;
    int     i;

    i = -1;
    d_x = cos(M_PI / 180 * vars->angle);
    d_y = sin(M_PI / 180 * vars->angle);
    while (++i < 55)
        mlx_pixel_put(vars->mlx, vars->win, vars->p_x + (i * d_x), vars->p_y - (i * d_y), color);
}