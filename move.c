/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:57:44 by mcreus            #+#    #+#             */
/*   Updated: 2023/04/14 13:40:07 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image(t_data *data, int y, int x, char flag)
{
	if (flag == 'A')
		mlx_put_image_to_window(data->mlx, data->win, data->playera_img,
			x * SIZE, y * SIZE);
	else if (flag == 'W')
		mlx_put_image_to_window(data->mlx, data->win, data->playerw_img,
			x * SIZE, y * SIZE);
	else if (flag == 'S')
		mlx_put_image_to_window(data->mlx, data->win, data->players_img,
			x * SIZE, y * SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->playerd_img,
			x * SIZE, y * SIZE);
}

int	ft_move_player(t_data *data, int y, int x, char flag)
{
	if (data->map[y][x] == '0' || data->map[y][x] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->floor_img,
			data->p_x * SIZE, data->p_y * SIZE);
		ft_put_image(data, y, x, flag);
		if (data->map[y][x] == 'C')
			data->collect -= 1;
		data->map[data->p_y][data->p_x] = '0';
		data->map[y][x] = '0';
		data->p_y = y;
		data->p_x = x;
		data->moves ++;
		return (1);
	}
	else if (data->map[y][x] == 'E' && data->collect == 0)
	{
		ft_printf("Total Moves: %d\n", data->moves + 1);
		ft_finish (data);
	}
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	int	result;

	result = 0;
	if (keysym == 65307)
		ft_finish (data);
	if (keysym == 119)
		result = ft_move_player(data, data->p_y - 1, data->p_x, 'W');
	if (keysym == 97)
		result = ft_move_player(data, data->p_y, data->p_x - 1, 'A');
	if (keysym == 115)
		result = ft_move_player(data, data->p_y + 1, data->p_x, 'S');
	if (keysym == 100)
		result = ft_move_player(data, data->p_y, data->p_x + 1, 'D');
	if (result == 1)
		ft_printf("Move number: %d\n", data->moves);
	return (0);
}
