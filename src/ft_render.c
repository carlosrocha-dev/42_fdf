/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:43:43 by caalbert          #+#    #+#             */
/*   Updated: 2023/01/29 19:22:47 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_scale_z(t_data *data, float_t factor)
{
	t_matrix3x3	ft_scale_z;
	t_matrix3x3	tmp;
	t_map		*map;

	map = data->map;
	tmp = (t_matrix3x3){map->init_x.x, map->init_x.y, map->init_x.z,
		map->init_y.x, map->init_y.y, map->init_y.z,
		map->init_z.x, map->init_z.y, map->init_z.z};
	ft_scale_z = (t_matrix3x3){1, 0, 0, 0, 1, 0, 0, 0, factor};
	ft_restore_map(data);
	ft_convert_map(map, ft_scale_z);
	ft_convert_map(map, tmp);
}

void	ft_zoom(t_map *map, float_t factor)
{
	t_matrix3x3	scale;

	scale = (t_matrix3x3){factor, 0, 0, 0, factor, 0, 0, 0, factor};
	ft_convert_map(map, scale);
}

void	ft_translate(t_map *map, t_pt offset)
{
	int		i;
	t_pt	*this;

	i = 0;
	while (i < map->x_dim * map->y_dim)
	{
		this = map->pt_arr + i;
		*this = ft_vec_add(*this, offset);
		i++;
	}
}

t_map	*ft_convert_map(t_map *map, t_matrix3x3 mat)
{
	int		i;
	t_pt	*this;

	i = 0;
	while (i < map->x_dim * map->y_dim)
	{
		this = map->pt_arr + i;
		*this = ft_mat_mult(mat, *this);
		i++;
	}
	map->init_x = ft_mat_mult(mat, map->init_x);
	map->init_y = ft_mat_mult(mat, map->init_y);
	map->init_z = ft_mat_mult(mat, map->init_z);
	return (map);
}
