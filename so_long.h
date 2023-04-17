/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:46:22 by mcreus            #+#    #+#             */
/*   Updated: 2023/04/14 13:31:42 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <fcntl.h>
# include <unistd.h>

# define WALL "./textures/mur.xpm"
# define FLOOR "./textures/fond_noir.xpm"
# define PLAYERA "./textures/mouvement_droite.xpm"
# define PLAYERD "./textures/mouvement_droite.xpm"
# define PLAYERW "./textures/mouvement_droite.xpm"
# define PLAYERS "./textures/mouvement_droite.xpm"
# define COLLECT "./textures/coins.xpm"
# define EXIT "./textures/sortie.xpm"
# define SIZE 50

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	void	*wall_img;
	void	*floor_img;
	void	*collect_img;
	void	*playera_img;
	void	*playerd_img;
	void	*playerw_img;
	void	*players_img;
	void	*exit_img;
	int		fd;
	int		lines;
	int		columns;
	char	**map;
	char	**map_dup;
	int		p_x;
	int		p_y;
	int		collect;
	int		moves;
	int		p;
	int		e;
}				t_data;

void	ft_check_map_file(t_data *d, char *file_name);

void	ft_fill_map_index(t_data *data);
void	ft_fill_window(t_data *data, int i, int j);
void	ft_read_map(t_data *data, char *argv);

int		ft_len(char const *str);
void	ft_init_stack(t_data *data);
int		ft_count_lines(t_data *data);

void	ft_check_columns(t_data *data);
void	ft_check_lines(t_data *data);
void	ft_check_rectangle(t_data *data);
void	ft_check_letters(t_data *data);
void	ft_check_walls(t_data *data);

void	ft_check_elements(t_data *data);
void	ft_map_dup(t_data *data);
int		ft_flood_fill(t_data *data, char **map, int x, int y);
void	ft_check_path(t_data *data);

void	ft_get_player_coordinates(t_data *data);
void	ft_get_imgs(t_data *data, char *argv);

int		ft_finish(t_data *data);
int		ft_finish2(t_data *data);
void	ft_free_map(t_data *data);
void	ft_free_map2(t_data *data);

void	ft_put_image(t_data *data, int y, int x, char flag);
int		ft_move_player(t_data *data, int y, int x, char flag);
int		handle_input(int keysym, t_data *data);

#endif
