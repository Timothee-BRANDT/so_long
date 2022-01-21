/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_print_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:35:32 by tbrandt           #+#    #+#             */
/*   Updated: 2022/01/21 18:50:07 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_size(t_data *data)
{
	data->x = ft_strlen(data->map[0]);
	data->y = ft_strlen2d(data->map);
}

void	init_struct(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->x * 32, data->y * 32, "so_long");
	data->i = 0;
	data->j = 0;
}

void	print_map(t_data *data)
{
	init_struct(data);
	while(data->map[data->i])
	{
		data->j = 0;
		while(data->map[data->i][data->j])
		{
			if (data->map[data->i][data->j] == '1')
				put_xpm("./img/wall.xpm", data);
			else if (data->map[data->i][data->j] == '0')
				put_xpm("./img/floor.xpm", data);
			else if (data->map[data->i][data->j] == 'C')
				put_double_xpm("./img/floor.xpm", "./img/collectible.xpm", data);
			else if (data->map[data->i][data->j] == 'E')
				put_double_xpm("./img/floor.xpm", "./img/exit.xpm", data);
			else if (data->map[data->i][data->j] == 'P')
				put_double_xpm("./img/floor.xpm", "./img/player_front.xpm", data);
			data->j++;
		}
		data->i++;
	}
	start_event(data);
}

void	put_xpm(char *file, t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx, file, &data->img_width, &data->img_height);
	if (!data->img)
	{
		printf("Error\nProblem with the images.");
		//free_split(data->map);
		exit(2);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, data->j * 32, data->i * 32);
}

void	put_double_xpm(char *file1, char *file2, t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx, file1, &data->img_width, &data->img_height);
	if (!data->img)
	{
		printf("Error\nProblem with the images.");
		//free_split(data->map);
		exit(2);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, data->j * 32, data->i * 32);
	data->img = mlx_xpm_file_to_image(data->mlx, file2, &data->img_width, &data->img_height);
	if (!data->img)
	{
		printf("Error\nProblem with the images.");
		//free_split(data->map);
		exit(2);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, data->j * 32, data->i * 32);
}
