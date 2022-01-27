/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:59:11 by tbrandt           #+#    #+#             */
/*   Updated: 2022/01/27 18:56:08 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		printf("Error\n");
	else
	{
		if (start_parsing(argv, &data) == 0)
		{
			get_map_size(&data);
			get_player_pos(&data);
			init_struct(&data);
			print_map(&data);
			start_event(&data);
		}
	}
}
