/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:58:11 by aliens            #+#    #+#             */
/*   Updated: 2021/04/12 14:57:11 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_params(t_map *map)
{
	t_params	vars;

	vars.px = 960;
	vars.py = 540;
	vars.angle = 90;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, map->r1, map->r2, "game of thrones");
	vars.img = mlx_new_image(vars.mlx, map->r1, map->r2);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bpp, &vars.ll, &vars.endian);
	player(&vars, 100100100);
	display_map(map, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 17, close_win, &vars);
	mlx_loop(vars.mlx);
}

void	init_map(char **argv)
{
	int		i;
	int		fd;
	char	*line;
	t_list	*charmap;
	t_map	map;

	i = 0;
	map.w_map = 0;
	charmap = NULL;
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return ;
	while (get_next_line(fd, &line) && i < 8)
		i += get_infos_map(line, &map);
	while (get_next_line(fd, &line))
		ft_lstadd_back(&charmap, ft_lstnew(line));
	printf("%d\n%d\n%d\n%d\n", map.r1, map.r2, map.f, map.c);
	printf("%s\n%s\n%s\n%s\n%s\n", map.so, map.we, map.no, map.ea, map.s);
	get_int_map(charmap, &map);
	init_params(&map);
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc <= 0)
		return (0);
	init_map(argv);
	return (0);
}
