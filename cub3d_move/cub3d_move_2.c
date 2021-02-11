/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_move_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 20:00:36 by aliens            #+#    #+#             */
/*   Updated: 2021/02/11 16:47:08 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_w(t_params *vars)
{
    float d_x;
    float d_y;

    player(*vars, 0);
    d_x = cos(M_PI / 180 * vars->angle) * 10;
    d_y = sin(M_PI / 180 * vars->angle) * 10;
    vars->p_x += d_x;
    vars->p_y -= d_y;
    player(*vars, 100100100);
}

void    ft_a(t_params *vars)
{
    float d_x;
    float d_y;

    player(*vars, 0);
    d_x = cos(M_PI / 180 * vars->angle) * 10;
    d_y = sin(M_PI / 180 * vars->angle) * 10;
    vars->p_x -= d_y;
    vars->p_y -= d_x;
    player(*vars, 100100100);
}

void    ft_s(t_params *vars)
{
    float d_x;
    float d_y;

    player(*vars, 0);
    d_x = cos(M_PI / 180 * vars->angle) * 10;
    d_y = sin(M_PI / 180 * vars->angle) * 10;
    vars->p_x -= d_x;
    vars->p_y += d_y;
    player(*vars, 100100100);
}

void    ft_d(t_params *vars)
{
    float d_x;
    float d_y;

    player(*vars, 0);
    d_x = cos(M_PI / 180 * vars->angle) * 10;
    d_y = sin(M_PI / 180 * vars->angle) * 10;
    vars->p_x += d_y;
    vars->p_y += d_x;
    player(*vars, 100100100);
}