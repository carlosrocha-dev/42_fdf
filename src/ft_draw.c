/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:43:04 by caalbert          #+#    #+#             */
/*   Updated: 2023/02/01 14:35:18 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	img_pix_put(t_img *img, t_pt pt)
{
	char	*pixel;
	int		x;
	int		y;

	x = round(pt.x);
	y = round(pt.y);
	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	pixel = img->addr + y * img->line_len + x * (img->bpp / 8);
	*(int *)pixel = pt.color;
}

void	ft_draw_map(t_img *img, t_map *map, t_pt offset)
{
	int		i;
	t_pt	pt;
	t_pt	neighbour_right;
	t_pt	neighbour_down;
	t_pt	*this;

	i = 0;
	while (i < map->x_dim * map->y_dim)
	{
		this = map->pt_arr + i;
		pt = ft_vec_add(*this, offset);
		if (i % map->x_dim != map->x_dim - 1)
		{
			neighbour_right = ft_vec_add(*(this + 1), offset);
			ft_edge(img, pt, neighbour_right);
		}
		if (i < map->x_dim * map->y_dim - map->x_dim)
		{
			neighbour_down = ft_vec_add(*(this + map->x_dim), offset);
			ft_edge(img, pt, neighbour_down);
		}
		i++;
	}
}

void	ft_render_bg(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			img_pix_put(img, (t_pt){j, i, 0, color});
			j++;
		}
		i++;
	}
}

void	ft_fdf_menu(t_data *data, int color)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 20,
		color, "Bonus part(controls of map):");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 40,
		color, "_____________________________________");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, (WIN_H / 2) - 240,
		color, "Increase and decrease map`s altitude: J, K");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, (WIN_H / 2) - 220,
		color, "Zoom: Keypad +, _");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, (WIN_H / 2) - 200,
		color, "Translate: Up, Down, Left, Right");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, (WIN_H / 2) - 180,
		color, "Rotate: W, A, S, D");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, (WIN_H / 2) - 160,
		color, "Reset view (ISO): R");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, (WIN_H / 2) - 140,
		color, "Top View: T");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, (WIN_H / 2) - 120,
		color, "Exit: Esc or X");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, (WIN_H) - 20,
		color, "Developed by: caalbert");
	mlx_string_put(data->mlx_ptr, data->win_ptr, (WIN_W) - 140, (WIN_H) - 20,
		color, "42 SP - 2023");
}
