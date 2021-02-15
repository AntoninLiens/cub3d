/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_res_and_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:44:23 by aliens            #+#    #+#             */
/*   Updated: 2021/02/15 18:08:27 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    get_R(char *line)
{
    t_map   map;
    char    **str;

    str = ft_split(line, ' ');
    map.R1 = ft_atoi(str[1]);
    map.R2 = ft_atoi(str[2]);
}

void    get_F(char *line)
{
    t_map   map;
    char    **str;

    str = ft_split(line, ',');
    map.F1 = ft_atoi(str[0]);
    map.F2 = ft_atoi(str[1]);
    map.F3 = ft_atoi(str[2]);
}

void    get_C(char *line)
{
    t_map   map;
    char    **str;

    str = ft_split(line, ',');
    map.C1 = ft_atoi(str[0]);
    map.C2 = ft_atoi(str[1]);
    map.C3 = ft_atoi(str[2]);
}