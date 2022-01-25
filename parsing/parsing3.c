/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:22:50 by tbrandt           #+#    #+#             */
/*   Updated: 2022/01/24 14:02:33 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	on_error(char *msg, int code)
{
	ft_putstr(msg);
	return (code);
}

int	start_parsing(char **argv, t_data *data)
{
	int	fd;
	int	count;

	count = 0;
	fd = open(argv[1], O_DIRECTORY);
	if (fd > 0)
		return (on_error("Error\nI can't read a directory.\n", 1));
	else
	{
		fd = open(argv[1], O_RDONLY);
		check_file(argv, fd);
		data->map = make_map(fd, &count);
		is_empty_map(&count, data->map);
		if (check_map(argv, data->map, fd, &count) == 1)
			return (1);
		if (check_map2(data->map) == 1)
			return (1);
	}
	return (0);
}

int	check_map(char **argv, char **map, int fd, int *count)
{	
	if (check_file(argv, fd) == 1)
		return (on_error("Error\nBad file extension.\n", 1));
	if (check_file(argv, fd) == 2)
		return (on_error("Error\nThis file doesn't exist.\n", 1));
	if (is_empty_map(count, map) == 1 || check_rectangle(map) == 1)
		return (on_error("Error\nMap is not rectangular.\n", 1));
	if (check_side_wall(map) == 1 || check_front_wall(map) == 1)
		return (on_error("Error\nThe map is not surrounded by walls.\n", 1));
	return (0);
}

int	check_map2(char **map)
{
	int	collectible;
	int	exit;
	int	player;

	collectible = 0;
	exit = 0;
	player = 0;
	check_inside(map, &collectible, &exit, &player);
	if (!collectible)
		return (on_error("Error\nI need collectibles.\n", 1));
	if (!exit)
		return (on_error("Error\nI need an exit door.\n", 1));
	if (!player || player == 2)
		return (on_error("Error\nI need one, and only one player.\n", 1));
	if (check_content(map))
		return(on_error("Error\nMy map only accept 0, 1, P, C and E.\n", 1));
	return (0);
}

void	free_split(char ** map)
{
	int	i;
	int	j;

	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
