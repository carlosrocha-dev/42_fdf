/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:43:08 by caalbert          #+#    #+#             */
/*   Updated: 2023/01/30 04:48:10 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_parse_edge(unsigned int i, char *s)
{
	(void)i;
	if (*s == '\n')
		*s = ' ';
}

void	ft_free_str_arr(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i] != NULL)
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}

int	ft_cols(char *s)
{
	int		cols;
	char	**split;
	char	*tmp;

	tmp = ft_strdup(s);
	cols = 0;
	ft_striteri(tmp, ft_parse_edge);
	split = ft_split(tmp, ' ');
	free(tmp);
	while (split[cols] != NULL)
		cols++;
	ft_free_str_arr(split);
	return (cols);
}

int	ft_parsing(t_data *data, char *filename)
{
	int		fd;
	char	*file;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Oops, failed to open file\n", 2);
		return (-1);
	}
	data->map = malloc(sizeof(t_map));
	if (data->map == NULL)
		return (-1);
	file = ft_read_file(fd, data);
	if (file == NULL)
		return (-1);
	ft_striteri(file, ft_parse_edge);
	data->parsed_file = ft_split(file, ' ');
	free(file);
	if (close(fd) == -1)
	{
		ft_putstr_fd("Could not close the file\n", 2);
		return (-1);
	}
	return (0);
}
