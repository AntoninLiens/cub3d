/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:10:13 by aliens            #+#    #+#             */
/*   Updated: 2021/04/16 15:36:31 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/includes/libft.h"
# include "./libft/includes/get_next_line.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct s_map
{
	int		r1;
	int		r2;
	int		f;
	int		c;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		**map;
	int		h_map;
	int		w_map;
	int		wall_size;
}				t_map;

typedef struct s_param
{
	void	*mlx;
	void	*win;
	int		px;
	int		py;
	int		angle;
}				t_param;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}				t_img;

typedef struct s_cub
{
	t_map	*map;
	t_param	*vars;
	t_img	*img;
	t_list	*charmap;
}				t_cub;

void			init_cub(t_cub *cub, char **argv);
void			init_map(char **argv, t_cub *cub);

int				get_infos_map(char *line, t_map *map);
char			*get_textures(char *line, int i);
void			get_int_map(t_list *charmap, t_map *map);
int				*int_line(t_list *charmap, t_map *map);
void			get_r(char *line, t_map *map);
void			get_f(char *line, t_map *map);
void			get_c(char *line, t_map *map);

int				create_rgb(int r, int g, int b);
int				close_win(t_param *vars);
int				is_wall(t_map *map, int x, int y);
void			put_pixel(t_img *img, int x, int y, int color);
void			player(t_cub *cub, int color);
void			display_map(t_cub *cub);
void			line(t_cub *cub, int color, float j);

int				key_hook(int keycode, t_cub *cub);
void			turn_left(t_param *vars);
void			turn_right(t_param *vars);
void			ft_w(t_param *vars);
void			ft_a(t_param *vars);
void			ft_s(t_param *vars);
void			ft_d(t_param *vars);

#endif
