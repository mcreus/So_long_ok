/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:59:30 by mcreus            #+#    #+#             */
/*   Updated: 2023/04/14 13:38:39 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_elements(t_data *data)
{
	if (data->p != 1)
	{
		ft_putstr_fd("Error\nWrong number of player elements!\n", 2);
		ft_finish2(data);
		exit (0);
	}
	else if (data->e != 1)
	{
		ft_putstr_fd("Error\nWrong number of exit elements!\n", 2);
		ft_finish2(data);
		exit (0);
	}
	else if (data->collect < 1)
	{
		ft_putstr_fd("Error\nWrong number of collectibles elements!\n", 2);
		ft_finish2(data);
		exit (0);
	}
	ft_check_path(data);
}

void	ft_map_dup(t_data *data)
{
	int	i;

	i = 0;
	data->map_dup = ft_calloc(data->lines + 1, sizeof(char *));
	while (i < data->lines)
	{
		data->map_dup[i] = ft_strdup(data->map[i]);
		i++;
	}
}

int	ft_flood_fill(t_data *data, char **map, int x, int y)
{
	static int	c;
	static int	e;

	if (y < 0 || x < 0 || y > data->lines || x > data->columns
		|| map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	if (map[y][x] == 'E')
	{	
		e++;
		map[y][x] = 'X';
		return (0);
	}
	if (map[y][x] == 'C')
		c++;
	map[y][x] = 'X';
	ft_flood_fill(data, map, x + 1, y);
	ft_flood_fill(data, map, x - 1, y);
	ft_flood_fill(data, map, x, y + 1);
	ft_flood_fill(data, map, x, y - 1);
	if (e == 1 && c == data->collect)
		return (1);
	else
		return (0);
}

void	ft_check_path(t_data *data)
{
	ft_map_dup(data);
	if (ft_flood_fill(data, data->map_dup, data->p_x, data->p_y) != 1)
	{
		ft_putstr_fd("Error\nInvalid Map Path\n", 2);
		ft_free_map2(data);
		ft_finish2(data);
	}
	else
		ft_free_map2(data);
}
