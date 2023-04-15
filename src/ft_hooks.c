/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:43:28 by caalbert          #+#    #+#             */
/*   Updated: 2023/01/29 01:26:45 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	ft_loop_hook(t_data *data)
{
	t_map	*map;
	t_pt	offset;

	if (data->win_ptr == NULL)
		return (1);
	ft_render_bg(&data->img, BLACK);
	map = data->map;
	offset.x = WIN_W / 2;
	offset.y = WIN_H / 2;
	offset.z = 0;
	ft_draw_map(&data->img, map, offset);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (0);
}

int	ft_key_hook(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_exit(data);
	return (0);
}

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	//mlx_destroy_display(data->mlx_ptr);
	free(data->map->pt_arr);
	free(data->map);
	free(data->bkp_map->pt_arr);
	free(data->bkp_map);
	free(data->mlx_ptr);
	ft_free_str_arr(data->parsed_file);
	exit(0);
	return (0);
}

int	start_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		ft_putstr_fd("Connection to server X could not be established\n", 2);
	if (data->mlx_ptr == NULL)
		return (-1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, WIN_T);
	if (data->win_ptr == NULL)
		ft_putstr_fd("A new window could not be created\n", 2);
	if (data->win_ptr == NULL)
		return (-1);
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	mlx_loop_hook(data->mlx_ptr, ft_loop_hook, data);
	mlx_hook(data->win_ptr, DestroyNotify, 0, ft_exit, data);
	mlx_hook(data->win_ptr, KeyPress, 1, ft_key_hook, data);
	mlx_do_key_autorepeaton(data->mlx_ptr);
	mlx_loop(data->mlx_ptr);
	return (0);
}
