/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_move_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:26:00 by aliens            #+#    #+#             */
/*   Updated: 2021/04/16 15:43:47 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_hook(int keycode, t_cub *cub)
{
	player(cub, 0);
	if (keycode == 53)
		exit(1);
	else if (keycode == 13)
		ft_w(cub->vars);
	else if (keycode == 0)
		ft_a(cub->vars);
	else if (keycode == 1)
		ft_s(cub->vars);
	else if (keycode == 2)
		ft_d(cub->vars);
	else if (keycode == 123)
		turn_left(cub->vars);
	else if (keycode == 124)
		turn_right(cub->vars);
	player(cub, 100100100);
	return (0);
}

void	turn_left(t_param *vars)
{
	vars->angle += 15;
	vars->angle %= 360;
}

void	turn_right(t_param *vars)
{
	vars->angle -= 15;
	vars->angle %= 360;
}
