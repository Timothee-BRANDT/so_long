/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:59:20 by tbrandt           #+#    #+#             */
/*   Updated: 2022/01/16 15:26:48 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h> // open
# include <unistd.h> // read
# include <stdio.h> // printf
# include <stdlib.h> // malloc
# include "Libft/libft.h"

char	**make_map(int fd, int *count);
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

#endif
