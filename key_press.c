/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:17:50 by tbrandt           #+#    #+#             */
/*   Updated: 2022/01/25 23:47:05 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player(char *file1, char *file2, t_data *data)
{
	data->img = mlx_xpm_file_to_image \
	(data->mlx, file1, &data->img_width, &data->img_height);
	if (!data->img)
	{
		printf("Error\nProblem with the images.");
		free_split(data->map);
		exit(2);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
	data->img, data->j_player * 32, data->i_player * 32);
	data->img = mlx_xpm_file_to_image(data->mlx, \
	file2, &data->img_width, &data->img_height);
	if (!data->img)
	{
		printf("Error\nProblem with the images.");
		free_split(data->map);
		exit(2);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
	data->img, data->j_player * 32, data->i_player * 32);
}

void	destroy_window(int keycode, t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->map);
	exit (2);
}

int	ft_close(t_data *data)
{
	destroy_window(0, data);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		destroy_window(0, data);
	if (keycode == KEY_W)
		move_w(data);
	if (keycode == KEY_A)
		move_a(data);
	if (keycode == KEY_S)
		move_s(data);
	if (keycode == KEY_D)
		move_d(data);
	return (0);
}

void	start_event(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 0, key_press, data);
	mlx_hook(data->mlx_win, 17, 0, ft_close, data);
	mlx_loop(data->mlx);
}
