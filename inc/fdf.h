/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:12:08 by caalbert          #+#    #+#             */
/*   Updated: 2023/05/22 11:14:59 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "/usr/X11/lib/mlx.h"
# include <stdio.h>
# include <math.h>
# include </opt/X11/include/X11/keysym.h>
# include <X11/X.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <Carbon/Carbon.h>

# define WIN_T			"FDF - 42SP (caalbert)"
# define WIN_T_BONUS	"FDF - 42SP (caalbert) - MACOS M1 version"
# define WIN_W			1580
# define WIN_H			1020
# define WHITE			0xFFFFFFFF
# define BLACK			0x000000
# define CORAL			0x9e3b42
# define CORAL_L		0xe4717a
# define BLUE			0x2196f3
# define CARMIN			0x3c0000
# define BONUS_BG		0x1E4758
# define EDGE			0x44b3bf
# define BONUS_TEXT		0x85ab6c
# define PLANE			BLUE
# define HIGHTER		CORAL
# define LOWER			CORAL_L
# define ISO			0.6

# ifdef __APPLE__
# define KEY_ESC		53
# define KEY_EQUAL		24
# define KEY_MINUS		27
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_W			13
# define KEY_S			1
# define KEY_D			2
# define KEY_A			0
# define KEY_K			40
# define KEY_J			38
# define KEY_T			17
# define KEY_R			15
# else
# define KEY_ESC		 XK_Escape
# define KEY_EQUAL		 XK_equal
# define KEY_MINUS		 XK_minus
# define KEY_LEFT		 XK_Left
# define KEY_RIGHT		 XK_Right
# define KEY_UP		 XK_Up
# define KEY_DOWN		 XK_Down
# define KEY_W		 XK_w
# define KEY_S		 XK_s
# define KEY_D		 XK_d
# define KEY_A		 XK_a
# define KEY_K		 XK_k
# define KEY_J		 XK_j
# define KEY_T		 XK_t
# define KEY_R		 XK_r
# endif

typedef struct s_pt
{
	float_t				x;
	float_t				y;
	float_t				z;
	int					color;
}						t_pt;

typedef struct s_map
{
	t_pt				*pt_arr;
	t_pt				init_x;
	t_pt				init_y;
	t_pt				init_z;
	int					x_dim;
	int					y_dim;
	int					space;
	int					min_height;
	int					max_height;
	int					min_x;
	int					max_x;
	int					min_y;
	int					max_y;
}						t_map;

typedef struct s_matrix3x3
{
	float_t				c1r1;
	float_t				c1r2;
	float_t				c1r3;
	float_t				c2r1;
	float_t				c2r2;
	float_t				c2r3;
	float_t				c3r1;
	float_t				c3r2;
	float_t				c3r3;
}						t_matrix3x3;

typedef struct s_img
{
	void				*mlx_img;
	char				*addr;
	int					bpp;
	int					line_len;
	int					endian;
}						t_img;

typedef struct s_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_img				img;
	t_map				*map;
	t_map				*bkp_map;
	char				**parsed_file;
	void				*img_ptr;
}						t_data;

float_t			convert_percent(int start, int end, int this);
t_map			*ft_mapping(t_data *data);
t_map			*ft_convert_map(t_map *map, t_matrix3x3 mat);
t_map			*ft_bkp_map(t_data *data);
t_pt			ft_mat_mult(t_matrix3x3 mat, t_pt pt);
t_pt			ft_vec_add(t_pt pt1, t_pt pt2);
t_pt			ft_vec_sub(t_pt pt1, t_pt pt2);
int				ft_key_hook(int keysym, t_data *data);
int				ft_key_hook_bonus(int keysym, t_data *data);
int				ft_exit(t_data *data);
int				ft_color_channel(int start, int end, float_t percentage);
int				ft_color(t_pt this, t_pt start, t_pt end, t_pt delta);
int				ft_gradient(t_pt this, t_pt start, t_pt end);
int				ft_edge_low(t_img *img, t_pt start, t_pt end);
int				ft_edge_high(t_img *img, t_pt start, t_pt end);
int				ft_edge(t_img *img, t_pt start, t_pt end);
int				ft_cols(char *s);
int				ft_parsing(t_data *data, char *filename);
int				start_mlx(t_data *data);
int				ft_loop_hook(t_data *data);
int				ft_verify_lines(int cols, t_data *data);
void			img_pix_put(t_img *img, t_pt pt);
char			*ft_read_file(int fd, t_data *data);
void			ft_draw_map(t_img *img, t_map *map, t_pt offset);
void			ft_render_bg(t_img *img, int color);
void			ft_parse_edge(unsigned int i, char *s);
void			ft_free_str_arr(char **str_arr);
void			ft_iso_viewport(t_map *map);
void			ft_cone_viewport(t_map *map);
void			ft_set_colors(t_map *map);
void			ft_set_height(t_map *map, t_pt *this);
void			ft_fill_map(t_data *data, t_map *map);
void			ft_zoom(t_map *map, float_t factor);
void			ft_translate(t_map *map, t_pt offset);
void			ft_rotate_x(t_map *map, float_t angle);
void			ft_rotate_y(t_map *map, float_t angle);
void			ft_scale_z(t_data *data, float_t factor);
void			ft_join_line(char **line, char **file);
void			ft_fdf_menu(t_data *data, int color);
void			ft_autoscale(t_map *map);
void			ft_restore_map(t_data *data);
void			ft_set_xy_min_max(t_map *map);
void			ft_put_png(t_data *data);

#endif
