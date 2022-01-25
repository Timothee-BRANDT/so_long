/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:17:50 by tbrandt           #+#    #+#             */
/*   Updated: 2022/01/25 15:11:40 by tbrandt          ###   ########.fr       */
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
	while(data->map[i])
	{
		j = 0;
		while(data->map[i][j])
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

void	put_player(char *file1, char *file2, t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx, file1, &data->img_width, &data->img_height);
	if (!data->img)
	{
		printf("Error\nProblem with the images.");
		free_split(data->map);
		exit(2);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, data->j_player * 32, data->i_player * 32);
	data->img = mlx_xpm_file_to_image(data->mlx, file2, &data->img_width, &data->img_height);
	if (!data->img)
	{
		printf("Error\nProblem with the images.");
		free_split(data->map);
		exit(2);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, data->j_player * 32, data->i_player * 32);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		free(data->map);
		exit(2);
	}
	if (keycode == KEY_W)
		move_w(data);
	if (keycode == KEY_A)
		move_a(data);
	 if(keycode == KEY_S)
		move_s(data);
	if(keycode == KEY_D)
		move_d(data);
	print_map(data);
	return (0);
}

void	start_event(t_data *data)
{
	//mlx_key_hook(data->mlx_win, key_press, data);
	mlx_hook(data->mlx_win, 2, 0, key_press, data);
	mlx_loop(data->mlx);
}
