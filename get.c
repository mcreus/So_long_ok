/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:56:15 by mcreus            #+#    #+#             */
/*   Updated: 2023/04/17 10:29:11 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_player_coordinates(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->lines)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->p_x = j;
				data->p_y = i;
				data->p ++;
			}
			if (data->map[i][j] == 'C')
				data->collect++;
			if (data->map[i][j] == 'E')
				data->e++;
			j++;
		}
		i++;
	}
	ft_check_elements(data);
}

void	ft_get_imgs(t_data *data, char *argv)
{
	data->floor_img = mlx_xpm_file_to_image(data->mlx,
			FLOOR, &data->x, &data->y);
	data->wall_img = mlx_xpm_file_to_image(data->mlx,
			WALL, &data->x, &data->y);
	data->playera_img = mlx_xpm_file_to_image(data->mlx,
			PLAYERA, &data->x, &data->y);
	data->playerd_img = mlx_xpm_file_to_image(data->mlx,
			PLAYERD, &data->x, &data->y);
	data->playerw_img = mlx_xpm_file_to_image(data->mlx,
			PLAYERW, &data->x, &data->y);
	data->players_img = mlx_xpm_file_to_image(data->mlx,
			PLAYERS, &data->x, &data->y);
	data->exit_img = mlx_xpm_file_to_image(data->mlx,
			EXIT, &data->x, &data->y);
	data->collect_img = mlx_xpm_file_to_image(data->mlx,
			COLLECT, &data->x, &data->y);
	ft_read_map(data, argv);
}
