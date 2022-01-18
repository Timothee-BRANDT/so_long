/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:16:40 by tbrandt           #+#    #+#             */
/*   Updated: 2022/01/18 12:13:08 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_file(char **argv, int fd)
{
	int	j;

	j = 0;
	if (fd == -1)
		return (2);
	while (argv[1][j] && argv[1][j] != '.')
		j++;
	if (ft_strncmp(".ber", &argv[1][j], 4) != 0 || ft_strlen(&argv[1][j]) > 4)
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
