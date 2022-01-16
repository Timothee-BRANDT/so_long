/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:59:11 by tbrandt           #+#    #+#             */
/*   Updated: 2022/01/16 15:26:13 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	int		fd;
	char	**map;
	int		count;

	map = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		check_file(argv, fd);
		map = make_map(fd, &count);
		is_empty_map(&count, map);
		if (check_map(argv, map, fd, &count) == 1)
			return (0);
		check_map2(map);
	}
	else
		printf("Error\n");
	//system("leaks so_long");
}
