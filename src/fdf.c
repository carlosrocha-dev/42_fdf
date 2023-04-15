/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:42:55 by caalbert          #+#    #+#             */
/*   Updated: 2023/01/28 23:37:19 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf <folder/file.fdf>\n", 2);
		return (-1);
	}
	if (ft_parsing(&data, argv[1]) == -1)
		return (-1);
	ft_mapping(&data);
	ft_iso_viewport(data.map);
	ft_autoscale(data.map);
	if (start_mlx(&data) == -1)
		return (-1);
	return (0);
}
