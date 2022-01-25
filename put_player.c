/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:33:37 by tbrandt           #+#    #+#             */
/*   Updated: 2022/01/25 23:50:37 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player_front(t_data *data)
{
	data->count++;
	put_player("./img/floor.xpm", "./img/floor.xpm", data);
	data->i_player++;
	put_player("./img/floor.xpm", "./img/player_front.xpm", data);
	data->map[data->i_player][data->j_player] = '0';
	data->moves++;
}

void	put_player_back(t_data *data)
{
	data->count++;
	put_player("./img/floor.xpm", "./img/floor.xpm", data);
	data->i_player--;
	put_player("./img/floor.xpm", "./img/player_back.xpm", data);
	data->map[data->i_player][data->j_player] = '0';
	data->moves++;
}

void	put_player_left(t_data *data)
{
	data->count++;
	put_player("./img/floor.xpm", "./img/floor.xpm", data);
	data->j_player--;
	put_player("./img/floor.xpm", "./img/player_left.xpm", data);
	data->map[data->i_player][data->j_player] = '0';
	data->moves++;
}

void	put_player_right(t_data *data)
{
	data->count++;
	put_player("./img/floor.xpm", "./img/floor.xpm", data);
	data->j_player++;
	put_player("./img/floor.xpm", "./img/player_right.xpm", data);
	data->map[data->i_player][data->j_player] = '0';
	data->moves++;
}
