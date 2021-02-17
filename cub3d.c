/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:58:11 by aliens            #+#    #+#             */
/*   Updated: 2021/02/17 13:40:41 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void     init_params(void)
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

void    init_map(char **argv)
{
    int     fd;
    t_map   map;
    char    *line;

    if (!(fd = open(argv[1], O_RDONLY)))
        return ;
    while (get_next_line(fd, &line))
    {
        if (line[0] == 'R')
            get_R(line);
        else if (line[0] == 'N' && line[1] == 'O')
            map.NO = get_NO(line);
        else if (line[0] == 'S' && line[1] == 'O')
            map.SO = get_SO(line);
        else if (line[0] == 'W' && line[1] == 'E')
            map.WE = get_WE(line);
        else if (line[0] == 'E' && line[1] == 'A')
            map.EA = get_EA(line);
        else if (line[0] == 'S')
            map.S = get_S(line);
        else if (line[0] == 'F')
            get_F(line);
        else if (line[0] == 'C')
            get_C(line);
    }
    close (fd);
}

int     main(int argc, char **argv)
{   
    if (argc <= 0)
        return (0);
    init_map(argv);
    init_params();
    return (0);
}