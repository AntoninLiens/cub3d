/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:10:13 by aliens            #+#    #+#             */
/*   Updated: 2021/02/15 13:45:27 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./get_next_line/get_next_line.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

typedef struct  s_params
{
    void    *mlx;
    void    *win;
    int     p_x;
    int     p_y;
    int     angle;
}               t_params;

typedef struct  s_map
{
    int     R1;
    int     R2;
    char    NO;
    char    SO;
    char    WE;
    char    EA;
    char    S;
    int     F1;
    int     F2;
    int     F3;
    int     C1;
    int     C2;
    int     C3;
    **int     map;
}

void    init(void);
void    player(t_params vars, int color);
void    line(t_params *vars, int color);
int     key_hook(int keycode, t_params *vars);
void    turn_left(t_params *vars);
void    turn_right(t_params *vars);
void    ft_w(t_params *vars);
void    ft_a(t_params *vars);
void    ft_s(t_params *vars);
void    ft_d(t_params *vars);

#endif