/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:58:11 by aliens            #+#    #+#             */
/*   Updated: 2021/02/07 16:56:57 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    player(t_params vars)
{
    int i;
    int j;
    int size;

    i = -1;
    size = 20;
    mlx_clear_window(vars.mlx, vars.win);
    while (++i < 10)
    {
        j = 1 + size - i * 2;
        while (--j)
            mlx_pixel_put(vars.mlx, vars.win, vars.p_x + j + i, vars.p_y - i, 071255123);
    }
}

int     key_hook(int keycode, t_params *vars)
{
    if (keycode == 53)
        exit(1);
    else if (keycode == 13)
        vars->p_y -= 5;
    else if (keycode == 1)
        vars->p_y += 5;
    else if (keycode == 0)
        vars->p_x -= 5;
    else if (keycode == 2)
        vars->p_x += 5;
    player(*vars);
    printf("%d\n", keycode);
    return (0);
}

void     init(void)
{
    t_params vars;

    vars.p_x = 960;
    vars.p_y = 540;
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "game of thrones");
    player(vars);
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_loop(vars.mlx);
}

int     main(void)
{
    init();
    return (0);
}