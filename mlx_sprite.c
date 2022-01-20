/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:35:32 by tbrandt           #+#    #+#             */
/*   Updated: 2022/01/20 18:54:26 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	read_image(char *path_file)
{
	t_data data;	

	data.mlx = mlx_init();
	data.relative_path = path_file;
	data.mlx_win = mlx_new_window(data.mlx, 1920, 1080, "so_long");
	data.img = mlx_xpm_file_to_image(data.mlx, data.relative_path, &data.img_width, &data.img_height);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_loop(data.mlx);
}*/

void	get_map_size(t_data *data)
{
	data->x = ft_strlen(data->map[0]);
	data->y = ft_strlen2d(data->map);
}

void	print_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while(data->map[i])
	{
		j = 0;
		while(data->map[i][j])
		{
			if (data->map[i][j] == '1')
				put_xpm("./img/wall.xpm", data, i, j);
			if (data->map[i][j] == '0')
				put_xpm("./img/floor.xpm", data, i, j);
			j++;
		}
		i++;
	}
}

void	put_xpm(char *file, t_data *data, int i, int j)
{
	data->mlx = mlx_init();
	data->relative_path = file;
	data->mlx_win = mlx_new_window(data->mlx, data->x * 32, data->y * 32, "so_long");
	data->img = mlx_xpm_file_to_image(data->mlx, data->relative_path, &data->img_width, &data->img_height);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, i * 32, j * 32);
	mlx_loop(data->mlx);
}
