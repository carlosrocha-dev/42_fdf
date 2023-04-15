/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:42:59 by caalbert          #+#    #+#             */
/*   Updated: 2023/01/26 22:43:00 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

float_t	convert_percent(int start, int end, int this)
{
	float_t	position;
	float_t	delta;

	delta = end - start;
	if (delta == 0)
		return (1.0);
	position = this - start;
	return (position / delta);
}

int	ft_channel(int start, int end, float_t percentage)
{
	int	color_channel;

	color_channel = (1 - percentage) * start + percentage * end;
	return (color_channel);
}

int	ft_color(t_pt this, t_pt start, t_pt end, t_pt delta)
{
	int		red;
	int		green;
	int		blue;
	float_t	percentage;

	if (this.color == end.color)
		return (this.color);
	if (delta.x > delta.y)
		percentage = convert_percent(start.x, end.x, this.x);
	else
		percentage = convert_percent(start.y, end.y, this.y);
	red = ft_channel((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, percentage);
	green = ft_channel((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, percentage);
	blue = ft_channel(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int	ft_gradient(t_pt this, t_pt start, t_pt end)
{
	int		red;
	int		green;
	int		blue;
	float_t	percentage;

	percentage = convert_percent(fabsf(start.z), fabsf(end.z), fabsf(this.z));
	red = ft_channel((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, percentage);
	green = ft_channel((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, percentage);
	blue = ft_channel(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
