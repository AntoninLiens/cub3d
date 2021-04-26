/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:15:47 by aliens            #+#    #+#             */
/*   Updated: 2021/04/26 16:52:53 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_map(t_cub *cub)
{
	int	i[2];

	i[0] = -1;
	while (++i[0] < cub->map->h_map)
	{
		i[1] = -1;
		while (++i[1] < cub->map->s_map[i[0]])
		{
			if (cub->map->map[i[0]][i[1]] == 'N' - '0' ||
			cub->map->map[i[0]][i[1]] == 'S' - '0' ||
			cub->map->map[i[0]][i[1]] == 'E' - '0' ||
			cub->map->map[i[0]][i[1]] == 'W' - '0')
				cub->map->map[i[0]][i[1]] =
				get_player_pos(cub, cub->map->map[i[0]][i[1]], i);
			if (cub->map->map[i[0]][i[1]] != 0 &&
			cub->map->map[i[0]][i[1]] != 1 && cub->map->map[i[0]][i[1]] != 2)
				exit(1);
		}
	}
}

int	get_player_pos(t_cub *cub, int d, int *i)
{
	if (cub->vars->angle != -1)
		exit(1);
	if (d == 'N' - '0')
		cub->vars->angle = 90;
	else if (d == 'S' - '0')
		cub->vars->angle = 270;
	else if (d == 'E' - '0')
		cub->vars->angle = 0;
	else if (d == 'W' - '0')
		cub->vars->angle = 180;	
	cub->vars->px = i[0] * cub->map->wall_size - cub->map->wall_size / 2;
	cub->vars->py = i[1] * cub->map->wall_size - cub->map->wall_size / 2;
	return (0);
}