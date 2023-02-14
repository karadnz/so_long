/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:54:21 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/14 13:58:57 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_window *window, t_img *img)
{
	int	*w;
	int	*h;

	w = &window->window_width;
	h = &window->window_height;
	window->mlx = mlx_init();
	window->mlx_win = mlx_new_window(window->mlx, *w, *h, "Azmut");
	printf("HIT\n");
	w = &img->img_width;
	h = &img->img_height;
	img->bg = mlx_xpm_file_to_image(window->mlx, "assets/bg.xpm", w, h);
	img->wall = mlx_xpm_file_to_image(window->mlx, "assets/w.xpm", w, h);
	init_coin(window, img, w, h);
	// img->coin = mlx_xpm_file_to_image(window->mlx, "assets/c0.xpm", w, h);
	img->pl_right = mlx_xpm_file_to_image(window->mlx, "assets/ct0.xpm", w, h);
	img->pl_left = mlx_xpm_file_to_image(window->mlx, "assets/ct1.xpm", w, h);
	img->exit = mlx_xpm_file_to_image(window->mlx, "assets/g0.xpm", w, h);
	img->exit_open = mlx_xpm_file_to_image(window->mlx, "assets/g1.xpm", w, h);
	window->img = img;
	img->look = 0;
	window->move_count = 0;
	window->x = get_p_xy(window, 'x');
	window->y = get_p_xy(window, 'y');
}

void	init_coin(t_window *window, t_img *img, int *w, int *h)
{
	img->coin = (void **)malloc(sizeof(void *) * 6);
	img->coin[0] = mlx_xpm_file_to_image(window->mlx, "assets/c/c0.xpm", w, h);
	img->coin[1] = mlx_xpm_file_to_image(window->mlx, "assets/c/c1.xpm", w, h);
	img->coin[2] = mlx_xpm_file_to_image(window->mlx, "assets/c/c2.xpm", w, h);
	img->coin[3] = mlx_xpm_file_to_image(window->mlx, "assets/c/c3.xpm", w, h);
	img->coin[4] = mlx_xpm_file_to_image(window->mlx, "assets/c/c4.xpm", w, h);
	img->coin[5] = mlx_xpm_file_to_image(window->mlx, "assets/c/c5.xpm", w, h);
	img->cindex = 0;
}