/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:10:13 by aliens            #+#    #+#             */
/*   Updated: 2021/05/03 12:45:31 by aliens           ###   ########.fr       */
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
	int		*s_map;
	int		h_map;
	int		w_map;
	int		wall_size;
}				t_map;

typedef struct s_param
{
	void	*mlx;
	void	*win;
	double	px;
	double	py;
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
void			put_pixel(t_img *img, int x, int y, int color);
int				create_rgb(int r, int g, int b);
int				close_win(t_param *vars);

int				get_infos_map(char *line, t_map *map);
char			*get_textures(char *line, int i);
void			get_r(char *line, t_map *map);
void			get_f(char *line, t_map *map);
void			get_c(char *line, t_map *map);
void			get_int_map(t_list *charmap, t_map *map);
int				*int_line(t_list *charmap, t_map *map);
void			check_map(t_cub *cub);
int				get_player_pos(t_cub *cub, int d, int *i);

void			player(t_cub *cub, int color);
void			line(t_cub *cub, int color, double j);
void			display_map(t_cub *cub, int color);
void			wall(t_cub *cub, int x, int y, int color);

int				key_hook(int keycode, t_cub *cub);
void			turn_left(t_param *vars);
void			turn_right(t_param *vars);
void			ft_w(t_cub *cub);
void			ft_a(t_cub *cub);
void			ft_s(t_cub *cub);
void			ft_d(t_cub *cub);

#endif
