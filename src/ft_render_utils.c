/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:57:41 by caalbert          #+#    #+#             */
/*   Updated: 2023/01/29 23:44:27 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_set_xy_min_max(t_map *map)
{
	t_pt	*this;
	int		i;

	i = 0;
	while (i < map->x_dim * map->y_dim)
	{
		this = map->pt_arr + i;
		if (this->x < map->min_x)
			map->min_x = this->x;
		if (this->x > map->max_x)
			map->max_x = this->x;
		if (this->y < map->min_y)
			map->min_y = this->y;
		if (this->y > map->max_y)
			map->max_y = this->y;
		i++;
	}
}

void	ft_autoscale(t_map *map)
{
	float_t	ft_scale_x;
	float_t	ft_scale_y;

	map->min_x = 0;
	map->max_x = 0;
	map->min_y = 0;
	map->max_y = 0;
	ft_set_xy_min_max(map);
	ft_scale_x = (WIN_W / 2 - 100) / fmaxf(abs(map->max_x), abs(map->min_x));
	ft_scale_y = (WIN_H / 2 - 100) / fmaxf(abs(map->max_y), abs(map->min_y));
	ft_zoom(map, fminf(ft_scale_x, ft_scale_y));
}

void	ft_restore_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map->x_dim * data->map->y_dim)
	{
		*(data->map->pt_arr + i) = *(data->bkp_map->pt_arr + i);
		i++;
	}
	data->map->init_x = (t_pt){1, 0, 0, 0x0};
	data->map->init_y = (t_pt){0, 1, 0, 0x0};
	data->map->init_z = (t_pt){0, 0, 1, 0x0};
}
