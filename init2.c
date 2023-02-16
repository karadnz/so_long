/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:07:05 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/16 17:10:30 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemy(t_window *window, t_img *img, int *w, int *h)
{
	img->enemy = (void **)malloc(sizeof(void *) * 22);
	img->enemy[0] = mlx_xpm_file_to_image(window->mlx, "a/e/e0.xpm", w, h);
	img->enemy[1] = mlx_xpm_file_to_image(window->mlx, "a/e/e1.xpm", w, h);
	img->enemy[2] = mlx_xpm_file_to_image(window->mlx, "a/e/e2.xpm", w, h);
	img->enemy[3] = mlx_xpm_file_to_image(window->mlx, "a/e/e3.xpm", w, h);
	img->enemy[4] = mlx_xpm_file_to_image(window->mlx, "a/e/e4.xpm", w, h);
	img->enemy[5] = mlx_xpm_file_to_image(window->mlx, "a/e/e5.xpm", w, h);
	img->enemy[6] = mlx_xpm_file_to_image(window->mlx, "a/e/e6.xpm", w, h);
	img->enemy[7] = mlx_xpm_file_to_image(window->mlx, "a/e/e7.xpm", w, h);
	img->enemy[8] = mlx_xpm_file_to_image(window->mlx, "a/e/e8.xpm", w, h);
	img->enemy[9] = mlx_xpm_file_to_image(window->mlx, "a/e/e9.xpm", w, h);
	img->enemy[10] = mlx_xpm_file_to_image(window->mlx, "a/e/e10.xpm", w, h);
	init_enemy_left(window, img, w, h);
}

void	init_enemy_left(t_window *window, t_img *img, int *w, int *h)
{
	int	i;

	img->enemy[11] = mlx_xpm_file_to_image(window->mlx, "a/e/el0.xpm", w, h);
	img->enemy[12] = mlx_xpm_file_to_image(window->mlx, "a/e/el1.xpm", w, h);
	img->enemy[13] = mlx_xpm_file_to_image(window->mlx, "a/e/el2.xpm", w, h);
	img->enemy[14] = mlx_xpm_file_to_image(window->mlx, "a/e/el3.xpm", w, h);
	img->enemy[15] = mlx_xpm_file_to_image(window->mlx, "a/e/el4.xpm", w, h);
	img->enemy[16] = mlx_xpm_file_to_image(window->mlx, "a/e/el5.xpm", w, h);
	img->enemy[17] = mlx_xpm_file_to_image(window->mlx, "a/e/el6.xpm", w, h);
	img->enemy[18] = mlx_xpm_file_to_image(window->mlx, "a/e/el7.xpm", w, h);
	img->enemy[19] = mlx_xpm_file_to_image(window->mlx, "a/e/el8.xpm", w, h);
	img->enemy[20] = mlx_xpm_file_to_image(window->mlx, "a/e/el9.xpm", w, h);
	img->enemy[21] = mlx_xpm_file_to_image(window->mlx, "a/e/el10.xpm", w, h);
	img->eindex = 0;
	img->enemies = (t_enemy **)malloc(sizeof(t_enemy *) * window->encount);
	i = 0;
	while (i < window->encount)
	{
		img->enemies[i] = (t_enemy *)malloc(sizeof(t_enemy));
		//img->enemies[i]->elook = 0;
		i++;
	}
	get_e_xy(window);
}

void	init_wnums(t_window *window, t_img *img)
{
	img->look = 0;
	window->move_count = 0;
	window->ccount = 0;
	window->ft = 0;
	window->dt = 0;
	window->x = get_p_xy(window, 'x');
	window->y = get_p_xy(window, 'y');
}
