/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:58:11 by aliens            #+#    #+#             */
/*   Updated: 2021/02/10 20:01:52 by aliens           ###   ########.fr       */
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
}

void     init(void)
{
    t_params vars;

    vars.p_x = 960;
    vars.p_y = 540;
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "game of thrones");
    player(vars, 100100100);
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_loop(vars.mlx);
}

int     main(void)
{
    init();
    return (0);
}