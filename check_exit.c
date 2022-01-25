/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:11:24 by tbrandt           #+#    #+#             */
/*   Updated: 2022/01/24 23:51:55 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_collectible(t_data *data)
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
			if (data->map[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	return (collectible);
}

int	check_collectible(t_data *data)
{
	int	i;

	i = count_collectible(data);
	printf(" total : %d\n", i);
	printf("compteur : %d", data->count);
	
	if (data->count >= i)
		return (1);
	return (0);
}
