/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:58:11 by aliens            #+#    #+#             */
/*   Updated: 2021/02/17 17:19:41 by aliens           ###   ########.fr       */
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
    int     i;
    int     fd;
    t_map   map;
    char    *line;

    i = 0;
    if (!(fd = open(argv[1], O_RDONLY)))
        return ;
    while (get_next_line(fd, &line) && i < 8)
    {
        if (line[0] == 'R' && ++i)
            get_R(line, &map);
        else if (line[0] == 'F' && ++i)
            get_F(line, &map);
        else if (line[0] == 'C' && ++i)
            get_C(line, &map);
        else if (line[0] == 'N' && line[1] == 'O' && ++i)
            map.NO = get_textures(line, 2);
        else if (line[0] == 'S' && line[1] == 'O' && ++i)
            map.SO = get_textures(line, 2);
        else if (line[0] == 'W' && line[1] == 'E' && ++i)
            map.WE = get_textures(line, 2);
        else if (line[0] == 'E' && line[1] == 'A' && ++i)
            map.EA = get_textures(line, 2);
        else if (line[0] == 'S' && ++i)
            map.S = get_textures(line, 1);
    }
    printf("%s\n%s\n%s\n%s\n%s\n", map.NO, map.SO, map.WE, map.EA, map.S);
    printf("%d\n%d\n%d\n%d\n", map.R1, map.R2, map.C, map.F);
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
