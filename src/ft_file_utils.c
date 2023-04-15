/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:43:24 by caalbert          #+#    #+#             */
/*   Updated: 2023/01/28 21:18:44 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

char	*ft_read_file(int fd, t_data *data)
{
	char	*line;
	char	*file;
	int		cols;

	line = "";
	file = malloc(sizeof(char));
	if (file == NULL)
		return (NULL);
	file[0] = '\0';
	data->map->y_dim = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			cols = ft_cols(line);
			if (!ft_verify_lines(cols, data))
				return (NULL);
			data->map->x_dim = cols;
			data->map->y_dim += 1;
			ft_join_line(&line, &file);
		}
	}
	return (file);
}

int	ft_verify_lines(int cols, t_data *data)
{
	if (data->map->y_dim != 0 && data->map->x_dim != cols)
	{
		ft_putstr_fd("The line length is worng.\n", 2);
		return (0);
	}
	return (1);
}

void	ft_join_line(char **line, char **file)
{
	char	*tmp;

	tmp = *file;
	*file = ft_strjoin(tmp, *line);
	free(tmp);
	free(*line);
	*line = "";
}
