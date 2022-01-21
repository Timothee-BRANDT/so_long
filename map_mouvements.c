/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mouvements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:17:50 by tbrandt           #+#    #+#             */
/*   Updated: 2022/01/21 18:25:36 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}*/

void	start_event(t_data *data)
{
	mlx_loop(data->mlx);
}
