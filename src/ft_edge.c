/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edge.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 02:11:39 by caalbert          #+#    #+#             */
/*   Updated: 2023/01/31 02:11:42 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	ft_edge_low(t_img *img, t_pt start, t_pt end)
{
	int		err;
	int		yi;
	t_pt	delta;
	t_pt	this;

	delta = ft_vec_sub(end, start);
	yi = 1;
	if (delta.y < 0)
		yi = -1;
	delta.y = fabsf(delta.y);
	err = 2 * delta.y - delta.x;
	this = start;
	while (this.x < end.x)
	{
		img_pix_put(img, this);
		if (err > 0)
			this.y += yi;
		if (err > 0)
			err = err + (2 * (delta.y - delta.x));
		else
			err = err + 2 * delta.y;
		this.color = ft_color(this, start, end, delta);
		this.x++;
	}
	return (0);
}

int	ft_edge_high(t_img *img, t_pt start, t_pt end)
{
	int		err;
	int		xi;
	t_pt	delta;
	t_pt	this;

	delta = ft_vec_sub(end, start);
	xi = 1;
	if (delta.x < 0)
		xi = -1;
	delta.x = fabsf(delta.x);
	err = 2 * delta.x - delta.y;
	this = start;
	while (this.y < end.y)
	{
		img_pix_put(img, this);
		if (err > 0)
			this.x += xi;
		if (err > 0)
			err = err + (2 * (delta.x - delta.y));
		else
			err = err + 2 * delta.x;
		this.color = ft_color(this, start, end, delta);
		this.y++;
	}
	return (0);
}

int	ft_edge(t_img *img, t_pt start, t_pt end)
{
	if (fabsf(end.y - start.y) < fabsf(end.x - start.x))
	{
		if (start.x > end.x)
			return (ft_edge_low(img, end, start));
		return (ft_edge_low(img, start, end));
	}
	if (start.y > end.y)
		return (ft_edge_high(img, end, start));
	return (ft_edge_high(img, start, end));
	return (-1);
}
