/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_move_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:26:00 by aliens            #+#    #+#             */
/*   Updated: 2021/02/17 16:56:16 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int     key_hook(int keycode, t_params *vars)
{
    player(*vars, 0);
    if (keycode == 53)
        exit(1);
    else if (keycode == 13)
        ft_w(vars);
    else if (keycode == 0)
        ft_a(vars);
    else if (keycode == 1)
        ft_s(vars);
    else if (keycode == 2)
        ft_d(vars);
    else if (keycode == 123)
        turn_left(vars);
    else if (keycode == 124)
        turn_right(vars);
    player(*vars, 100100100);
    return (0);
}

void    turn_left(t_params *vars)
{
    player(*vars, 0);
    vars->angle += 45;
    vars->angle %= 360;
    player(*vars, 100100100);
}

void    turn_right(t_params *vars)
{
    player(*vars, 0);
    vars->angle -= 45;
    vars->angle %= 360;
    player(*vars, 100100100);
}
