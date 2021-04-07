/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_move_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 20:00:36 by aliens            #+#    #+#             */
/*   Updated: 2021/04/07 17:03:25 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_w(t_params *vars)
{
	float	dx;
	float	dy;

	dx = cos(M_PI / 180 * vars->angle) * 10;
	dy = sin(M_PI / 180 * vars->angle) * 10;
	vars->px += dx;
	vars->py -= dy;
}

void	ft_a(t_params *vars)
{
	float	dx;
	float	dy;

	dx = cos(M_PI / 180 * vars->angle) * 10;
	dy = sin(M_PI / 180 * vars->angle) * 10;
	vars->px -= dy;
	vars->py -= dx;
}

void	ft_s(t_params *vars)
{
	float	dx;
	float	dy;

	dx = cos(M_PI / 180 * vars->angle) * 10;
	dy = sin(M_PI / 180 * vars->angle) * 10;
	vars->px -= dx;
	vars->py += dy;
}

void	ft_d(t_params *vars)
{
	float	dx;
	float	dy;

	dx = cos(M_PI / 180 * vars->angle) * 10;
	dy = sin(M_PI / 180 * vars->angle) * 10;
	vars->px += dy;
	vars->py += dx;
}
