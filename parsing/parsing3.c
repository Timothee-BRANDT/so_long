/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:22:50 by tbrandt           #+#    #+#             */
/*   Updated: 2022/01/16 15:29:55 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map(char **argv, char **map, int fd, int *count)
{
	if (check_file(argv, fd) == 1)
	{
		printf("Error\nBad file extension.\n");
		return (1);
	}
	if (check_file(argv, fd) == 2)
	{
		printf("Error\nThis file doesn't exist.\n");
		return (1);
	}
	if (is_empty_map(count, map) == 1 || check_rectangle(map) == 1)
	{
		printf("Error\nThe map is empty or not rectangular.\n");
		return (1);
	}
	if (check_side_wall(map) == 1 || check_front_wall(map) == 1)
	{
		printf("Error\nThe map is not surrounded by walls.\n");
		return (1);
	}
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
	if (!collectible || !exit || !player || player == 2 || check_content(map))
	{
		printf("Error\nThere is a problem with the content of the map.\n");
		return (1);
	}
	return (0);
}
