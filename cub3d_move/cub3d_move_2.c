/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_move_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 20:00:36 by aliens            #+#    #+#             */
/*   Updated: 2021/04/27 18:06:45 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_w(t_cub *cub)
{
	float	dx;
	float	dy;

	dx = cos(M_PI / 180 * cub->vars->angle) * 10;
	dy = sin(M_PI / 180 * cub->vars->angle) * 10;
	cub->vars->px += dx;
	cub->vars->py -= dy;
//	printf("%f | %f\n", dx, dy);
}

void	ft_a(t_cub *cub)
{
	float	dx;
	float	dy;

	dx = cos(M_PI / 180 * cub->vars->angle) * 10;
	dy = sin(M_PI / 180 * cub->vars->angle) * 10;
	cub->vars->px -= dy;
	cub->vars->py -= dx;
}

void	ft_s(t_cub *cub)
{
	float	dx;
	float	dy;

	dx = cos(M_PI / 180 * cub->vars->angle) * 10;
	dy = sin(M_PI / 180 * cub->vars->angle) * 10;
	cub->vars->px -= dx;
	cub->vars->py += dy;
}

void	ft_d(t_cub *cub)
{
	float	dx;
	float	dy;

	dx = cos(M_PI / 180 * cub->vars->angle) * 10;
	dy = sin(M_PI / 180 * cub->vars->angle) * 10;
	cub->vars->px += dy;
	cub->vars->py += dx;
}
