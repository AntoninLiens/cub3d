/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:10:13 by aliens            #+#    #+#             */
/*   Updated: 2021/04/06 13:54:10 by aliens           ###   ########.fr       */
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

typedef struct	s_params
{
	void	*mlx;
	void	*win;
	int		px;
	int		py;
	int		angle;
}				t_params;

typedef struct	s_map
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
}				t_map;

void			init_params(void);

void			init_map(char **argv);
int				get_infos_map(char *line, t_map *map);
char			*get_textures(char *line, int i);
void			get_int_map(t_list *charmap, t_map *map);
int				*int_line(t_list *charmap, t_map *map);
void			get_r(char *line, t_map *map);
void			get_f(char *line, t_map *map);
void			get_c(char *line, t_map *map);

int				create_rgb(int r, int g, int b);
int				close_win(t_params *vars);
void			player(t_params vars, int color);
void			line(t_params *vars, int color, float j);

int				key_hook(int keycode, t_params *vars);
void			turn_left(t_params *vars);
void			turn_right(t_params *vars);
void			ft_w(t_params *vars);
void			ft_a(t_params *vars);
void			ft_s(t_params *vars);
void			ft_d(t_params *vars);

#endif
