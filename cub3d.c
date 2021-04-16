/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:58:11 by aliens            #+#    #+#             */
/*   Updated: 2021/04/16 15:39:18 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(char **argv, t_cub *cub)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	cub->charmap = NULL;
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return ;
	while (get_next_line(fd, &line) && i < 8)
		i += get_infos_map(line, cub->map);
	while (get_next_line(fd, &line))
		ft_lstadd_back(&cub->charmap, ft_lstnew(line));
	printf("%d\n%d\n%d\n%d\n", cub->map->r1, cub->map->r2, cub->map->f, cub->map->c);
	printf("%s\n%s\n%s\n%s\n%s\n", cub->map->so, cub->map->we, cub->map->no, cub->map->ea, cub->map->s);
	get_int_map(cub->charmap, cub->map);
	close(fd);
}

void	init_cub(t_cub *cub, char **argv)
{
	cub->map = malloc(sizeof(t_map));
	cub->vars = malloc(sizeof(t_param));
	cub->img = malloc(sizeof(t_img));
	cub->charmap = malloc(sizeof(t_list));
	init_map(argv, cub);
	cub->vars->px = cub->map->r1 / 2;
	cub->vars->py = cub->map->r2 / 2;
	cub->vars->angle = 90;
	cub->vars->mlx = mlx_init();
	cub->vars->win = mlx_new_window(cub->vars->mlx, cub->map->r1, cub->map->r2, "game of thrones");
	cub->img->img = mlx_new_image(cub->vars->mlx, cub->map->r1, cub->map->r2);
	cub->img->addr = mlx_get_data_addr(cub->img->img, &cub->img->bpp, &cub->img->ll, &cub->img->endian);
	display_map(cub);
	player(cub, 100100100);
	mlx_hook(cub->vars->win, 2, 1L << 0, key_hook, cub);
	mlx_hook(cub->vars->win, 17, 1L << 17, close_win, cub->vars);
	printf("angle = %d\n", cub->vars->angle);
	mlx_loop(cub->vars->mlx);
}

int	main(int argc, char **argv)
{
	t_cub cub;

	if (argc != 2)
		return (0);
	init_cub(&cub, argv);
	return (0);
}
