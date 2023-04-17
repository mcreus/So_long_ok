/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:45:06 by mcreus            #+#    #+#             */
/*   Updated: 2023/04/14 13:20:39 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_file(t_data *data, char *file_name)
{
	int	i;

	i = 0;
	data->fd = open(file_name, O_RDONLY);
	i = ft_strlen(file_name) - 1;
	while (file_name[i] != '.')
		i--;
	if (ft_strncmp((file_name + i), ".ber", 4) != 0)
	{
		ft_putstr_fd("Error\nInvalid file type\n", 2);
		close(data->fd);
		exit(1);
	}
	if (data->fd < 0)
	{
		ft_putstr_fd("Error\nInvalid FD\n", 2);
		close(data->fd);
		exit(1);
	}
	close(data->fd);
	data->fd = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nCheck the input-->./so_long <Map path>\n", 2);
		return (0);
	}	
	ft_init_stack(&data);
	if (argc == 2)
	{
		ft_check_map_file(&data, argv[1]);
		data.mlx = mlx_init();
		if (data.mlx == NULL)
			return (0);
		ft_get_imgs(&data, argv[1]);
		mlx_hook(data.win, KeyPress, KeyPressMask, handle_input, &data);
		mlx_hook(data.win, DestroyNotify, ButtonPressMask, ft_finish, &data);
		mlx_loop(data.mlx);
	}
	return (0);
}
