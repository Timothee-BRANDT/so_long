/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:59:20 by tbrandt           #+#    #+#             */
/*   Updated: 2022/01/25 23:50:54 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h> // open
# include <unistd.h> // read
# include <stdio.h> // printf
# include <stdlib.h> // malloc
# include "mlx/mlx.h"
# include "Libft/libft.h"

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53

typedef struct s_data {
	char	**map;
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
	int		i;
	int		j;
	int		i_player;
	int		j_player;
	int		count;
	int		collectible;
	int		exit;
	int		player;
	int		moves;
}			t_data;

char	**make_map(int fd, int *count);
int		start_parsing(char **argv, t_data *data);
int		on_error(char *msg, int code);
int		check_file(char **argv, int fd);
int		check_side_wall(char **map);
int		check_front_wall(char **map);
int		check_rectangle(char **map);
int		check_content(char **map);
int		count_zero(char **map);
int		is_empty_map(int *count, char **map);
int		check_map(char **argv, char **map, int fd, int *count);
int		check_map2(char **map, t_data *data);
void	check_inside(char **map, t_data *data);
void	read_image(char *path_file);
void	get_map_size(t_data *data);
void	print_map(t_data *data);
void	put_xpm(char *file, t_data *data);
void	put_double_xpm(char *file1, char *file2, t_data *data);
void	put_player(char *file1, char *file2, t_data *data);
void	put_player_front(t_data *data);
void	put_player_back(t_data *data);
void	put_player_left(t_data *data);
void	put_player_right(t_data *data);
void	start_event(t_data *data);
void	free_split(char **map);
void	init_struct(t_data *data);
void	get_player_pos(t_data *data);
void	move_w(t_data *data);
void	move_a(t_data *data);
void	move_s(t_data *data);
void	move_d(t_data *data);
int		check_collectible(t_data *data);
int		ft_close(t_data *data);
void	destroy_window(int keycode, t_data *data);

#endif
