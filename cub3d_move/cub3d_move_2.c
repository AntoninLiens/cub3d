/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_move_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 20:00:36 by aliens            #+#    #+#             */
/*   Updated: 2021/05/03 12:57:06 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_w(t_cub *cub)
{
	double	dx;
	double	dy;
	int	i;
	int	j;

	dx = cos(M_PI / 180 * cub->vars->angle) * 1 / 3;
	dy = sin(M_PI / 180 * cub->vars->angle) * 1 / 3;
	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
		if (cub->map->map[(int)(cub->vars->py + i / 3 - 1 / 6 - dy)]
		[(int)(cub->vars->px + j / 3 - 1 / 6 + dx)] == 1)
			return ;
	}
	cub->vars->px += dx;
	cub->vars->py -= dy;
}

void	ft_a(t_cub *cub)
{
	double	dx;
	double	dy;
	int	i;
	int	j;

	dx = cos(M_PI / 180 * cub->vars->angle) * 1 / 3;
	dy = sin(M_PI / 180 * cub->vars->angle) * 1 / 3;
	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
		if (cub->map->map[(int)(cub->vars->py + i / 3 - 1 / 6 - dx)]
		[(int)(cub->vars->px + j / 3 - 1 / 6 - dy)] == 1)
			return ;
	}
	cub->vars->px -= dy;
	cub->vars->py -= dx;
}

void	ft_s(t_cub *cub)
{
	double	dx;
	double	dy;
	int	i;
	int	j;

	dx = cos(M_PI / 180 * cub->vars->angle) * 1 / 3;
	dy = sin(M_PI / 180 * cub->vars->angle) * 1 / 3;
	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
		if (cub->map->map[(int)(cub->vars->py + i / 3 - 1 / 6 + dy)]
		[(int)(cub->vars->px + j / 3 - 1 / 6 - dx)] == 1)
			return ;
	}
	cub->vars->px -= dx;
	cub->vars->py += dy;
}

void	ft_d(t_cub *cub)
{
	double	dx;
	double	dy;
	int	i;
	int	j;

	dx = cos(M_PI / 180 * cub->vars->angle) * 1 / 3;
	dy = sin(M_PI / 180 * cub->vars->angle) * 1 / 3;
	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
		if (cub->map->map[(int)(cub->vars->py + i / 3 - 1 / 6 + dy)]
		[(int)(cub->vars->px + j / 3 - 1 / 6 + dx)] == 1)
			return ;
	}
	cub->vars->px += dy;
	cub->vars->py += dx;
}
