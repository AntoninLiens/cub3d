/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:58:11 by aliens            #+#    #+#             */
/*   Updated: 2021/02/11 17:17:35 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void     init(void)
{
    t_params vars;

    vars.p_x = 960;
    vars.p_y = 540;
    vars.angle = 90;
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "game of thrones");
    player(vars, 100100100);
    mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
    mlx_loop(vars.mlx);
}

int     main(void)
{
    init();
    return (0);
}