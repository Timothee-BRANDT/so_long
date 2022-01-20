/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:59:11 by tbrandt           #+#    #+#             */
/*   Updated: 2022/01/20 18:54:28 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data data;
	if (argc == 2)
	{
		if (start_parsing(argv, &data) == 0)
		{
			get_map_size(&data);
			print_map(&data);
		}
	}
	else
		printf("Error\n");
	//system("leaks so_long");
}
