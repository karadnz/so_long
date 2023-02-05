/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:54:21 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/05 07:34:31 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_window *window, t_img *img)
{
	
	window->mlx = mlx_init();
	window->mlx_win = mlx_new_window(window->mlx, window->window_width, window->window_height, "Azmut");
	window->relative_path = "assets/azmutjpg.xpm";
	//window->img = mlx_xpm_file_to_image(window->mlx, window->relative_path, &window->img_width, &window->img_height);


	window->bg = mlx_xpm_file_to_image(window->mlx, "assets/grass.xpm", &window->img_width, &window->img_height);
	window->wall = mlx_xpm_file_to_image(window->mlx, "assets/wall.xpm", &window->img_width, &window->img_height);


	img->bg = mlx_xpm_file_to_image(window->mlx, "assets/stone.xpm", &img->img_width, &img->img_height);
	img->wall = mlx_xpm_file_to_image(window->mlx, "assets/wall2.xpm", &img->img_width, &img->img_height);
	img->coin = mlx_xpm_file_to_image(window->mlx, "assets/coin.xpm", &img->img_width, &img->img_height);
	img->player_right = mlx_xpm_file_to_image(window->mlx, "assets/cat_right.xpm", &img->img_width, &img->img_height);
	img->player_left = mlx_xpm_file_to_image(window->mlx, "assets/cat_left.xpm", &img->img_width, &img->img_height);
	img->exit = mlx_xpm_file_to_image(window->mlx, "assets/gate.xpm", &img->img_width, &img->img_height);
	img->exit_open = mlx_xpm_file_to_image(window->mlx, "assets/gate_open.xpm", &img->img_width, &img->img_height);
	window->img = img;

	img->look = 0;

	window->move_count = 0;
	
}