/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:54:21 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/05 02:18:46 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_window *window)
{
	
	window->mlx = mlx_init();
	window->mlx_win = mlx_new_window(window->mlx, window->window_width, window->window_height, "Azmut");
	window->relative_path = "assets/azmutjpg.xpm";
	//window->img = mlx_xpm_file_to_image(window->mlx, window->relative_path, &window->img_width, &window->img_height);

	window->bg = mlx_xpm_file_to_image(window->mlx, "assets/grass.xpm", &window->img_width, &window->img_height);
	window->wall = mlx_xpm_file_to_image(window->mlx, "assets/wall.xpm", &window->img_width, &window->img_height);
	
}