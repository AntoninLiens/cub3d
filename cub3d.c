/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:58:11 by aliens            #+#    #+#             */
/*   Updated: 2021/02/21 14:48:22 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_params(void)
{
	t_params vars;

	vars.px = 960;
	vars.py = 540;
	vars.angle = 90;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "game of thrones");
	player(vars, 100100100);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_loop(vars.mlx);
}

void	init_map(char **argv)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	t_list	*charmap;
	t_map	map;

	i = 0;
	j = -1;
	charmap = NULL;
	if (!(fd = open(argv[1], O_RDONLY)))
		return ;
	while (get_next_line(fd, &line) && i < 8)
		i += get_infos_map(line, &map);
	while (get_next_line(fd, &line))
	{
		charmap = ft_lstnew(line);
		printf("%s\n", charmap->content);
		charmap = charmap->next;
	}
	printf("%d\n%d\n%d\n%d\n", map.r1, map.r2, map.f, map.c);
	printf("%s\n%s\n%s\n%s\n%s\n", map.so, map.we, map.no, map.ea, map.s);
	close(fd);
}

int		main(int argc, char **argv)
{
	if (argc <= 0)
		return (0);
	init_map(argv);
	init_params();
	return (0);
}
