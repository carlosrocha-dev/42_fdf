/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_viewport.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 09:24:36 by caalbert          #+#    #+#             */
/*   Updated: 2023/01/31 02:28:21 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_rotate_x(t_map *map, float_t angle)
{
	t_matrix3x3	rot_x;

	rot_x = (t_matrix3x3){
		1, 0, 0,
		0, cos(angle), -sin(angle),
		0, sin(angle), cos(angle)};
	ft_convert_map(map, rot_x);
}

void	ft_rotate_y(t_map *map, float_t angle)
{
	t_matrix3x3	rot_y;

	rot_y = (t_matrix3x3){
		cos(angle), 0, sin(angle),
		0, 1, 0,
		-sin(angle), 0, cos(angle)};
	ft_convert_map(map, rot_y);
}

void	ft_rotate_z(t_map *map, float_t angle)
{
	t_matrix3x3	rot_z;

	rot_z = (t_matrix3x3){
		cos(angle), -sin(angle), 0,
		sin(angle), cos(angle), 0,
		0, 0, 1};
	ft_convert_map(map, rot_z);
}

void	ft_iso_viewport(t_map *map)
{
	ft_rotate_x(map, -M_PI_2);
	ft_rotate_y(map, M_PI_4);
	ft_rotate_x(map, ISO);
}
