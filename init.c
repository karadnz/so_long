/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:54:21 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/16 17:22:22 by mkaraden         ###   ########.fr       */
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
	w = &img->img_width;
	h = &img->img_height;
	img->bg = mlx_xpm_file_to_image(window->mlx, "a/bg.xpm", w, h);
	img->wall = mlx_xpm_file_to_image(window->mlx, "a/w.xpm", w, h);
	init_coin(window, img, w, h);
	init_hbar(window, img, w, h);
	init_nums(window, img, w, h);
	init_player(window, img, w, h);
	img->exit = mlx_xpm_file_to_image(window->mlx, "a/g0.xpm", w, h);
	img->exit_open = mlx_xpm_file_to_image(window->mlx, "a/g1.xpm", w, h);
	img->hearth = mlx_xpm_file_to_image(window->mlx, "a/h.xpm", w, h);
	img->paw = mlx_xpm_file_to_image(window->mlx, "a/paw.xpm", w, h);
	img->cmini = mlx_xpm_file_to_image(window->mlx, "a/cmini.xpm", w, h);
	window->img = img;
	init_wnums(window, img);
	get_en_count(window);
	init_enemy(window, img, w, h);
}

void	init_coin(t_window *window, t_img *img, int *w, int *h)
{
	img->coin = (void **)malloc(sizeof(void *) * 6);
	img->coin[0] = mlx_xpm_file_to_image(window->mlx, "a/c/c0.xpm", w, h);
	img->coin[1] = mlx_xpm_file_to_image(window->mlx, "a/c/c1.xpm", w, h);
	img->coin[2] = mlx_xpm_file_to_image(window->mlx, "a/c/c2.xpm", w, h);
	img->coin[3] = mlx_xpm_file_to_image(window->mlx, "a/c/c3.xpm", w, h);
	img->coin[4] = mlx_xpm_file_to_image(window->mlx, "a/c/c4.xpm", w, h);
	img->coin[5] = mlx_xpm_file_to_image(window->mlx, "a/c/c5.xpm", w, h);
	img->cindex = 0;
}

void	init_hbar(t_window *window, t_img *img, int *w, int *h)
{
	img->hbar = (void **)malloc(sizeof(void *) * 4);
	img->hbar[0] = mlx_xpm_file_to_image(window->mlx, "a/h/hbar0.xpm", w, h);
	img->hbar[1] = mlx_xpm_file_to_image(window->mlx, "a/h/hbar1.xpm", w, h);
	img->hbar[2] = mlx_xpm_file_to_image(window->mlx, "a/h/hbar2.xpm", w, h);
	img->hbar[3] = mlx_xpm_file_to_image(window->mlx, "a/h/hbar3.xpm", w, h);
	window->health = 3;
}

void	init_nums(t_window *window, t_img *img, int *w, int *h)
{
	img->nums = (void **)malloc(sizeof(void *) * 10);
	img->nums[0] = mlx_xpm_file_to_image(window->mlx, "a/n/0.xpm", w, h);
	img->nums[1] = mlx_xpm_file_to_image(window->mlx, "a/n/1.xpm", w, h);
	img->nums[2] = mlx_xpm_file_to_image(window->mlx, "a/n/2.xpm", w, h);
	img->nums[3] = mlx_xpm_file_to_image(window->mlx, "a/n/3.xpm", w, h);
	img->nums[4] = mlx_xpm_file_to_image(window->mlx, "a/n/4.xpm", w, h);
	img->nums[5] = mlx_xpm_file_to_image(window->mlx, "a/n/5.xpm", w, h);
	img->nums[6] = mlx_xpm_file_to_image(window->mlx, "a/n/6.xpm", w, h);
	img->nums[7] = mlx_xpm_file_to_image(window->mlx, "a/n/7.xpm", w, h);
	img->nums[8] = mlx_xpm_file_to_image(window->mlx, "a/n/8.xpm", w, h);
	img->nums[9] = mlx_xpm_file_to_image(window->mlx, "a/n/9.xpm", w, h);
}

void	init_player(t_window *window, t_img *img, int *w, int *h)
{
	img->cat = (void **)malloc(sizeof(void *) * 4);
	img->cat[0] = mlx_xpm_file_to_image(window->mlx, "a/w/wr.xpm", w, h);
	img->cat[1] = mlx_xpm_file_to_image(window->mlx, "a/w/wl.xpm", w, h);
	img->cat[2] = mlx_xpm_file_to_image(window->mlx, "a/w/wf.xpm", w, h);
	img->cat[3] = mlx_xpm_file_to_image(window->mlx, "a/w/wb.xpm", w, h);
}
