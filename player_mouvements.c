/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mouvements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:48:02 by tbrandt           #+#    #+#             */
/*   Updated: 2022/01/25 23:50:00 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_pos(t_data *data)
{
	int	i;
	int	j;
	int	collectible;

	collectible = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->i_player = i;
				data->j_player = j;
			}
			j++;
		}
		i++;
	}
}

void	move_w(t_data *data)
{
	data->map[data->i_player][data->j_player] = '0';
	if (data->map[data->i_player - 1][data->j_player] != '1')
	{
		if (data->map[data->i_player - 1][data->j_player] == 'E')
		{
			if (check_collectible(data) == 1)
			{
				free_split(data->map);
				exit(EXIT_SUCCESS);
			}
		}
		else if (data->map[data->i_player - 1][data->j_player] == 'C')
			put_player_back(data);
		else if (data->map[data->i_player][data->j_player] == '0')
		{
			put_player("./img/floor.xpm", "./img/floor.xpm", data);
			data->i_player--;
			put_player("./img/floor.xpm", "./img/player_back.xpm", data);
			data->moves++;
		}
		if (data->map[data->i_player - 1][data->j_player] != 'E')
			printf("Number of moves : %d\n", data->moves);
	}
}

void	move_a(t_data *data)
{	
	data->map[data->i_player][data->j_player] = '0';
	if (data->map[data->i_player][data->j_player - 1] != '1')
	{
		if (data->map[data->i_player][data->j_player - 1] == 'E')
		{
			if (check_collectible(data) == 1)
			{
				free_split(data->map);
				exit(EXIT_SUCCESS);
			}
		}
		else if (data->map[data->i_player][data->j_player - 1] == 'C')
			put_player_left(data);
		else if (data->map[data->i_player][data->j_player - 1] == '0')
		{
			put_player("./img/floor.xpm", "./img/floor.xpm", data);
			data->j_player--;
			put_player("./img/floor.xpm", "./img/player_left.xpm", data);
			data->moves++;
		}
		if (data->map[data->i_player][data->j_player - 1] != 'E')
			printf("Number of moves : %d\n", data->moves);
	}
}

void	move_s(t_data *data)
{
	data->map[data->i_player][data->j_player] = '0';
	if (data->map[data->i_player + 1][data->j_player] != '1')
	{
		if (data->map[data->i_player + 1][data->j_player] == 'E')
		{
			if (check_collectible(data) == 1)
			{
				free_split(data->map);
				exit(EXIT_SUCCESS);
			}
		}
		else if (data->map[data->i_player + 1][data->j_player] == 'C')
			put_player_front(data);
		else if (data->map[data->i_player + 1][data->j_player] == '0')
		{
			put_player("./img/floor.xpm", "./img/floor.xpm", data);
			data->i_player++;
			put_player("./img/floor.xpm", "./img/player_front.xpm", data);
			data->moves++;
		}
		if (data->map[data->i_player + 1][data->j_player] != 'E')
			printf("Number of moves : %d\n", data->moves);
	}
}

void	move_d(t_data *data)
{
	data->map[data->i_player][data->j_player] = '0';
	if (data->map[data->i_player][data->j_player + 1] != '1')
	{
		if (data->map[data->i_player][data->j_player + 1] == 'E')
		{
			if (check_collectible(data) == 1)
			{
				free_split(data->map);
				exit(EXIT_SUCCESS);
			}
		}
		else if (data->map[data->i_player][data->j_player + 1] == 'C')
			put_player_right(data);
		else if (data->map[data->i_player][data->j_player + 1] == '0')
		{
			put_player("./img/floor.xpm", "./img/floor.xpm", data);
			data->j_player++;
			put_player("./img/floor.xpm", "./img/player_right.xpm", data);
			data->moves++;
		}
		if (data->map[data->i_player][data->j_player + 1] != 'E')
			printf("Number of moves : %d\n", data->moves);
	}
}
