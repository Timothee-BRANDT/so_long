/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:20:00 by tbrandt           #+#    #+#             */
/*   Updated: 2022/01/21 17:41:03 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

	i = count_zero(map);
	j = *count;
	if (j != i)
		return (1);
	return (0);
}

void	check_inside(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->collectible = 0;
	data->exit = 0;
	data->player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				data->collectible++;
			if (map[i][j] == 'E')
				data->exit++;
			if (map[i][j] == 'P')
				data->player++;
			j++;
		}
		i++;
	}
}
