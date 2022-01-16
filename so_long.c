/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:59:11 by tbrandt           #+#    #+#             */
/*   Updated: 2022/01/16 14:58:00 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**make_map(int fd, int *count)
{
	int		read_value;
	char	buffer[2];
	char	*line;
	char	**map;

	line = NULL;
	map = NULL;
	read_value = 1;
	while (read_value > 0)
	{
		read_value = read(fd, buffer, 1);
		if (buffer[0] == '\n')
			(*count)++;
		buffer[read_value] = '\0';
		line = ft_gnl_join(line, buffer);
	}
	map = ft_split(line, '\n');
	free(line);
	return (map);
}

int	check_file(char **argv, int fd)
{
	int	j;

	j = 0;
	if (fd == -1)
		return (2);
	while (argv[1][j] && argv[1][j] != '.')
		j++;
	if (ft_strncmp(".ber", &argv[1][j], 4) != 0 || ft_strlen(&argv[1][j]) == 3)
		return (1);
	return (0);
}

int	check_side_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
			return (1);
		if (map[i][ft_strlen(map[i]) - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_front_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		if (map[0][j] != '1')
			return (1);
		if (map[ft_strlen2d(map) - 1][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	count_zero(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j + 1] == '\0')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	is_empty_map(int *count, char **map)
{
	int	i;
	int	j;
	int	k;

	i = count_zero(map);
	j = *count;
	if (j != i)
		return (1);
	return (0);
}

void	check_inside(char **map, int *collectible, int *exit, int *player)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				(*collectible)++;
			if (map[i][j] == 'E')
				(*exit)++;
			if (map[i][j] == 'P')
				(*player)++;
			j++;
		}
		i++;
	}
}

int	check_rectangle(char **map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i - 1]))
			return (1);
		i++;
	}
	return (0);
}

int	check_content(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' \
				&& map[i][j] != 'C' && map[i][j] != 'E' \
				&& map[i][j] != 'P')
				return (1);
			j++;
		}
		i++;
	}	
	return (0);
}

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

int	main(int argc, char *argv[])
{
	int		fd;
	char	**map;
	int		count;

	map = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		check_file(argv, fd);
		map = make_map(fd, &count);
		is_empty_map(&count, map);
		if (check_map(argv, map, fd, &count) == 1)
			return (0);
		check_map2(map);
	}
	else
		printf("Error\n");
	//system("leaks so_long");
}
