/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mouvements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:48:02 by tbrandt           #+#    #+#             */
/*   Updated: 2022/01/25 15:11:39 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		{
			data->count++;
			put_player("./img/floor.xpm", "./img/floor.xpm", data);
			data->i_player--;
			put_player("./img/floor.xpm", "./img/player_back.xpm", data);
			data->map[data->i_player][data->j_player] = '0';
		}
		else if (data->map[data->i_player][data->j_player] == '0')
		{
			put_player("./img/floor.xpm", "./img/floor.xpm", data);
			data->i_player--;
			put_player("./img/floor.xpm", "./img/player_back.xpm", data);
		}
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
		{
			data->count++;
			put_player("./img/floor.xpm", "./img/floor.xpm", data);
			data->j_player--;
			put_player("./img/floor.xpm", "./img/player_left.xpm", data);
			data->map[data->i_player][data->j_player] = '0';
		}
		else if (data->map[data->i_player][data->j_player - 1] == '0')
		{
			put_player("./img/floor.xpm", "./img/floor.xpm", data);
			data->j_player--;
			put_player("./img/floor.xpm", "./img/player_left.xpm", data);
		}
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
		{
			data->count++;
			put_player("./img/floor.xpm", "./img/floor.xpm", data);
			data->i_player++;
			put_player("./img/floor.xpm", "./img/player_front.xpm", data);
			data->map[data->i_player][data->j_player] = '0';
		}
		else if (data->map[data->i_player + 1][data->j_player] == '0')
		{
			put_player("./img/floor.xpm", "./img/floor.xpm", data);
			data->i_player++;
			put_player("./img/floor.xpm", "./img/player_front.xpm", data);
		}
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
		{
			data->count++;
			put_player("./img/floor.xpm", "./img/floor.xpm", data);
			data->j_player++;
			put_player("./img/floor.xpm", "./img/player_right.xpm", data);
			data->map[data->i_player][data->j_player] = '0';
		}
		else if (data->map[data->i_player][data->j_player + 1] == '0')
		{
			put_player("./img/floor.xpm", "./img/floor.xpm", data);
			data->j_player++;
			put_player("./img/floor.xpm", "./img/player_right.xpm", data);
		}
	}
}