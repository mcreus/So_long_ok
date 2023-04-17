/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:57:03 by mcreus            #+#    #+#             */
/*   Updated: 2023/04/14 13:39:38 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_fill_map_index(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	while (i <= data->lines)
	{
		str = get_next_line(data->fd);
		if (!str)
		{
			free(str);
			break ;
		}
		data->map[i] = ft_strtrim(str, "\n");
		free (str);
		i++;
	}
	data->columns = ft_strlen(data->map[0]);
	ft_check_lines(data);
	ft_check_rectangle(data);
}

void	ft_fill_window(t_data *data, int i, int j)
{
	while (i < data->lines)
	{
		j = 0;
		while (data->map[i][j] != '\n' && data->map[i][j] != '\0')
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win,
					data->wall_img, j * SIZE, i * SIZE);
			else if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->win,
					data->floor_img, j * SIZE, i * SIZE);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->collect_img, j * SIZE, i * SIZE);
			else if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win,
					data->playerd_img, j * SIZE, i * SIZE);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win,
					data->exit_img, j * SIZE, i * SIZE);
			j++;
		}
		i++;
	}
}

void	ft_read_map(t_data *data, char *argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->fd = open(argv, O_RDONLY);
	data->lines = ft_count_lines(data);
	close (data->fd);
	data->fd = open(argv, O_RDONLY);
	data->map = ft_calloc(data->lines + 1, sizeof(char *));
	ft_fill_map_index(data);
	data->win = mlx_new_window(data->mlx, ft_len(data->map[0]) * SIZE,
			data->lines * SIZE, "so_long");
	if (data->win == NULL)
	{
		free(data->win);
		return ;
	}
	ft_fill_window(data, i, j);
	close (data->fd);
}
