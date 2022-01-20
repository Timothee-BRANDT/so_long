/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:59:20 by tbrandt           #+#    #+#             */
/*   Updated: 2022/01/20 18:03:37 by tbrandt          ###   ########.fr       */
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
int		check_map2(char **map);
void	check_inside(char **map, int *collectible, int *exit, int *player);
void	read_image(char *path_file);
void	get_map_size(t_data *data);
void	print_map(t_data *data);
void	put_xpm(char *file, t_data *data, int i, int j);

#endif
