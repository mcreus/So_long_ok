/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:26:35 by mcreus            #+#    #+#             */
/*   Updated: 2023/04/17 10:26:40 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_finish(t_data *data)
{
	mlx_destroy_image(data->mlx, data->floor_img);
	mlx_destroy_image(data->mlx, data->wall_img);
	mlx_destroy_image(data->mlx, data->playera_img);
	mlx_destroy_image(data->mlx, data->playerd_img);
	mlx_destroy_image(data->mlx, data->playerw_img);
	mlx_destroy_image(data->mlx, data->players_img);
	mlx_destroy_image(data->mlx, data->exit_img);
	mlx_destroy_image(data->mlx, data->collect_img);
	ft_free_map(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	ft_finish2(t_data *data)
{
	mlx_destroy_image(data->mlx, data->floor_img);
	mlx_destroy_image(data->mlx, data->wall_img);
	mlx_destroy_image(data->mlx, data->playera_img);
	mlx_destroy_image(data->mlx, data->playerd_img);
	mlx_destroy_image(data->mlx, data->playerw_img);
	mlx_destroy_image(data->mlx, data->players_img);
	mlx_destroy_image(data->mlx, data->exit_img);
	mlx_destroy_image(data->mlx, data->collect_img);
	mlx_destroy_display(data->mlx);
	if (data->map != 0)
		ft_free_map(data);
	free(data->mlx);
	exit(0);
}

void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	ft_free_map2(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_dup[i])
	{
		free(data->map_dup[i]);
		i++;
	}
	free(data->map_dup);
}
