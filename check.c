/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:53:42 by mcreus            #+#    #+#             */
/*   Updated: 2023/04/14 15:24:40 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_columns(t_data *data)
{
	if (data->columns < 3)
	{
		ft_putstr_fd("Error\nYou will need more columns in your map!\n", 2);
		ft_finish2(data);
		exit (0);
	}
}

void	ft_check_lines(t_data *data)
{
	if (data->lines < 3)
	{
		ft_putstr_fd("Error\nYou will need more lines in your map!\n", 2);
		ft_finish2(data);
		exit (0);
	}
	ft_check_columns(data);
}

void	ft_check_rectangle(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->lines)
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (j == data->columns)
			i++;
		else
		{
			ft_putstr_fd("Error\nThis map is not a rectangle!\n", 2);
			ft_finish2(data);
			exit(0);
		}
	}
	ft_check_letters(data);
}

void	ft_check_letters(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->lines)
	{
		x = 0;
		while (x < data->columns)
		{
			if (data->map[y][x] == '1' || data->map[y][x] == '0' ||
				data->map[y][x] == 'C' || data->map[y][x] == 'P' ||
				data->map[y][x] == 'E')
				x++;
			else
			{
				ft_putstr_fd("Error\n Invalid elements in the map\n", 2);
				ft_finish2(data);
			}
		}
		y++;
	}
	ft_check_walls(data);
}

void	ft_check_walls(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->columns)
	{
		if (data->map[0][i] != '1' || data->map[data->lines - 1][i] != '1')
		{
			ft_putstr_fd("Error\nWall not valid!\n", 2);
			ft_finish2(data);
		}
		i++;
	}
	i = 1;
	while (i < data->lines - 1)
	{
		if (data->map[i][0] != '1' || data->map[i][data->columns - 1] != '1')
		{
			ft_putstr_fd("Error\nWall not valid!\n", 2);
			ft_finish2(data);
		}
		i++;
	}
	ft_get_player_coordinates(data);
}
