/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:57:32 by caalbert          #+#    #+#             */
/*   Updated: 2023/01/29 04:21:20 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_map	*ft_mapping(t_data *data)
{
	t_map	*map;

	map = data->map;
	map->min_height = 0;
	map->max_height = 0;
	map->init_x = (t_pt){1, 0, 0, 0x0};
	map->init_y = (t_pt){0, 1, 0, 0x0};
	map->init_z = (t_pt){0, 0, 1, 0x0};
	map->pt_arr = malloc(map->x_dim * map->y_dim * sizeof(t_pt));
	if (map->pt_arr == NULL)
		return (NULL);
	map->space = 10;
	ft_fill_map(data, map);
	ft_set_colors(map);
	ft_bkp_map(data);
	return (map);
}

t_map	*ft_bkp_map(t_data *data)
{
	t_pt	*this;
	int		i;

	data->bkp_map = malloc(sizeof(t_map));
	if (data->bkp_map == NULL)
		return (NULL);
	data->bkp_map->pt_arr = malloc(data->map->x_dim
			* data->map->y_dim * sizeof(t_pt));
	if (data->bkp_map->pt_arr == NULL)
		return (NULL);
	i = 0;
	while (i < data->map->x_dim * data->map->y_dim)
	{
		this = data->map->pt_arr + i;
		*(data->bkp_map->pt_arr + i) = *this;
		i++;
	}
	return (data->bkp_map);
}

void	ft_fill_map(t_data *data, t_map *map)
{
	int		i;
	int		j;
	t_pt	*this;
	t_pt	pt;

	pt.z = 0;
	pt.y = -map->space * map->y_dim / 2;
	i = 0;
	while (i < map->y_dim)
	{
		pt.x = -map->space * map->x_dim / 2;
		j = 0;
		while (j < map->x_dim)
		{
			this = map->pt_arr + i * map->x_dim + j;
			*this = pt;
			this->z = ft_atoi(data->parsed_file[i * map->x_dim + j]);
			ft_set_height(map, this);
			this->color = EDGE;
			pt.x += map->space;
			j++;
		}
		pt.y += map->space;
		i++;
	}
}

void	ft_set_height(t_map *map, t_pt *this)
{
	if (this->z < map->min_height)
		map->min_height = this->z;
	if (this->z > map->max_height)
		map->max_height = this->z;
}

void	ft_set_colors(t_map *map)
{
	t_pt	plane;
	t_pt	max;
	t_pt	min;
	t_pt	*this;
	int		i;

	plane = (t_pt){0, 0, 0, EDGE};
	max = (t_pt){0, 0, map->max_height, HIGHTER};
	min = (t_pt){0, 0, map->min_height, LOWER};
	i = 0;
	while (i < map->x_dim * map->y_dim)
	{
		this = map->pt_arr + i;
		if (this->z > 0)
			this->color = ft_gradient(*this, plane, max);
		if (this->z < 0)
			this->color = ft_gradient(*this, plane, min);
		i++;
	}
}
