/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:58:34 by mcreus            #+#    #+#             */
/*   Updated: 2023/04/14 13:42:02 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_len(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_init_stack(t_data *data)
{
	data->collect_img = 0;
	data->exit_img = 0;
	data->fd = 0;
	data->floor_img = 0;
	data->lines = 0;
	data->columns = 0;
	data->map = 0;
	data->map_dup = 0;
	data->mlx = 0;
	data->playera_img = 0;
	data->playerd_img = 0;
	data->playerw_img = 0;
	data->players_img = 0;
	data->wall_img = 0;
	data->win = 0;
	data->x = 0;
	data->y = 0;
	data->p_x = 0;
	data->p_y = 0;
	data->collect = 0;
	data->moves = 0;
	data->e = 0;
	data->p = 0;
}

int	ft_count_lines(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	while (1)
	{
		str = get_next_line(data->fd);
		if (!str)
			break ;
		free(str);
		i++;
	}
	free (str);
	return (i);
}
