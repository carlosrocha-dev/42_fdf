/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:43:32 by caalbert          #+#    #+#             */
/*   Updated: 2023/05/22 11:16:02 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
# include <Carbon/Carbon.h>

int	ft_loop_hook(t_data *data)
{
	t_map	*map;
	t_pt	offset;

	if (data->win_ptr == NULL)
		return (1);
	ft_render_bg(&data->img, BONUS_BG);
	map = data->map;
	offset.x = (WIN_W / 2);
	offset.y = (WIN_H / 2);
	offset.z = 0;
	ft_draw_map(&data->img, map, offset);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	ft_fdf_menu(data, BONUS_TEXT);
	return (0);
}

int	ft_key_hook(int keysym, t_data *data)
{
	if (keysym == KEY_ESC)
		ft_exit(data);
	if (keysym == KEY_EQUAL)
		ft_zoom(data->map, 1.6);
	if (keysym == KEY_MINUS)
		ft_zoom(data->map, 1 / 1.6);
	if (keysym == KEY_LEFT)
		ft_translate(data->map, (t_pt){-10, 0, 0, 0});
	if (keysym == KEY_RIGHT)
		ft_translate(data->map, (t_pt){10, 0, 0, 0});
	if (keysym == KEY_UP)
		ft_translate(data->map, (t_pt){0, -10, 0, 0});
	if (keysym == KEY_DOWN)
		ft_translate(data->map, (t_pt){0, 10, 0, 0});
	if (keysym == KEY_W)
		ft_rotate_x(data->map, -0.1);
	if (keysym == KEY_S)
		ft_rotate_x(data->map, 0.1);
	else
		ft_key_hook_bonus(keysym, data);
	return (0);
}

int	ft_key_hook_bonus(int keysym, t_data *data)
{
	if (keysym == KEY_D)
		ft_rotate_y(data->map, -0.1);
	if (keysym == KEY_A)
		ft_rotate_y(data->map, 0.1);
	if (keysym == KEY_K)
		ft_scale_z(data, 1.1);
	if (keysym == KEY_J)
		ft_scale_z(data, 1 / 1.1);
	if (keysym == KEY_T)
	{
		ft_restore_map(data);
		ft_autoscale(data->map);
	}
	if (keysym == KEY_R)
	{
		ft_restore_map(data);
		ft_iso_viewport(data->map);
		ft_autoscale(data->map);
	}
	return (0);
}

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
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
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, WIN_T_BONUS);
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
