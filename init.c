/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:54:21 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/15 18:25:09 by mkaraden         ###   ########.fr       */
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
	init_hbar(window, img, w, h);
	init_nums(window, img, w, h);
	
	init_player(window, img, w, h);
	
	// img->coin = mlx_xpm_file_to_image(window->mlx, "assets/c0.xpm", w, h);
	//img->pl_right = mlx_xpm_file_to_image(window->mlx, "assets/w/wr.xpm", w, h);
	//img->pl_left = mlx_xpm_file_to_image(window->mlx, "assets/w/wl.xpm", w, h);
	img->exit = mlx_xpm_file_to_image(window->mlx, "assets/g0.xpm", w, h);
	img->exit_open = mlx_xpm_file_to_image(window->mlx, "assets/g1.xpm", w, h);
	img->hearth = mlx_xpm_file_to_image(window->mlx, "assets/h.xpm", w, h);
	img->paw = mlx_xpm_file_to_image(window->mlx, "assets/paw.xpm", w, h);
	img->cmini = mlx_xpm_file_to_image(window->mlx, "assets/cmini.xpm", w, h);
	window->img = img;
	img->look = 0;
	window->move_count = 0;
	window->ccount = 0;
	window->lm = 0; //
	window->dt = 0; //
	window->x = get_p_xy(window, 'x');
	window->y = get_p_xy(window, 'y');

	get_en_count(window);
	init_enemy(window, img, w, h);
	
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


void	init_hbar(t_window *window, t_img *img, int *w, int *h)
{
	img->hbar = (void **)malloc(sizeof(void *) * 4);
	img->hbar[0] = mlx_xpm_file_to_image(window->mlx, "assets/h/hbar0.xpm", w, h);
	img->hbar[1] = mlx_xpm_file_to_image(window->mlx, "assets/h/hbar1.xpm", w, h);
	img->hbar[2] = mlx_xpm_file_to_image(window->mlx, "assets/h/hbar2.xpm", w, h);
	img->hbar[3] = mlx_xpm_file_to_image(window->mlx, "assets/h/hbar3.xpm", w, h);
	window->health = 3;
}

void	init_nums(t_window *window, t_img *img, int *w, int *h)
{
	img->nums = (void **)malloc(sizeof(void *) * 10);
	img->nums[0] = mlx_xpm_file_to_image(window->mlx, "assets/n/0.xpm", w, h);
	img->nums[1] = mlx_xpm_file_to_image(window->mlx, "assets/n/1.xpm", w, h);
	img->nums[2] = mlx_xpm_file_to_image(window->mlx, "assets/n/2.xpm", w, h);
	img->nums[3] = mlx_xpm_file_to_image(window->mlx, "assets/n/3.xpm", w, h);
	img->nums[4] = mlx_xpm_file_to_image(window->mlx, "assets/n/4.xpm", w, h);
	img->nums[5] = mlx_xpm_file_to_image(window->mlx, "assets/n/5.xpm", w, h);
	img->nums[6] = mlx_xpm_file_to_image(window->mlx, "assets/n/6.xpm", w, h);
	img->nums[7] = mlx_xpm_file_to_image(window->mlx, "assets/n/7.xpm", w, h);
	img->nums[8] = mlx_xpm_file_to_image(window->mlx, "assets/n/8.xpm", w, h);
	img->nums[9] = mlx_xpm_file_to_image(window->mlx, "assets/n/9.xpm", w, h);;
}

void	init_enemy(t_window *window, t_img *img, int *w, int *h)
{
	img->enemy = (void **)malloc(sizeof(void *) * 22);
	
	img->enemy[0] = mlx_xpm_file_to_image(window->mlx, "assets/e/e0.xpm", w, h);
	img->enemy[1] = mlx_xpm_file_to_image(window->mlx, "assets/e/e1.xpm", w, h);
	img->enemy[2] = mlx_xpm_file_to_image(window->mlx, "assets/e/e2.xpm", w, h);
	img->enemy[3] = mlx_xpm_file_to_image(window->mlx, "assets/e/e3.xpm", w, h);
	img->enemy[4] = mlx_xpm_file_to_image(window->mlx, "assets/e/e4.xpm", w, h);
	img->enemy[5] = mlx_xpm_file_to_image(window->mlx, "assets/e/e5.xpm", w, h);
	img->enemy[6] = mlx_xpm_file_to_image(window->mlx, "assets/e/e6.xpm", w, h);
	img->enemy[7] = mlx_xpm_file_to_image(window->mlx, "assets/e/e7.xpm", w, h);
	img->enemy[8] = mlx_xpm_file_to_image(window->mlx, "assets/e/e8.xpm", w, h);
	img->enemy[9] = mlx_xpm_file_to_image(window->mlx, "assets/e/e9.xpm", w, h);
	img->enemy[10] = mlx_xpm_file_to_image(window->mlx, "assets/e/e10.xpm", w, h);

	img->enemy[11] = mlx_xpm_file_to_image(window->mlx, "assets/e/el0.xpm", w, h);
	img->enemy[12] = mlx_xpm_file_to_image(window->mlx, "assets/e/el1.xpm", w, h);
	img->enemy[13] = mlx_xpm_file_to_image(window->mlx, "assets/e/el2.xpm", w, h);
	img->enemy[14] = mlx_xpm_file_to_image(window->mlx, "assets/e/el3.xpm", w, h);
	img->enemy[15] = mlx_xpm_file_to_image(window->mlx, "assets/e/el4.xpm", w, h);
	img->enemy[16] = mlx_xpm_file_to_image(window->mlx, "assets/e/el5.xpm", w, h);
	img->enemy[17] = mlx_xpm_file_to_image(window->mlx, "assets/e/el6.xpm", w, h);
	img->enemy[18] = mlx_xpm_file_to_image(window->mlx, "assets/e/el7.xpm", w, h);
	img->enemy[19] = mlx_xpm_file_to_image(window->mlx, "assets/e/el8.xpm", w, h);
	img->enemy[20] = mlx_xpm_file_to_image(window->mlx, "assets/e/el9.xpm", w, h);
	img->enemy[21] = mlx_xpm_file_to_image(window->mlx, "assets/e/el10.xpm", w, h);

	printf("%d\n",window->encount);
	img->eindex = 0;
	img->enemies = (t_enemy **)malloc(sizeof(t_enemy *) * window->encount);
	int	i;
	i = 0;
	while (i < window->encount)
	{
		img->enemies[i] = (t_enemy *)malloc(sizeof(t_enemy));
		i++;
	}
	get_e_xy(window);
	printf("AAA\n");

}

void	init_player(t_window *window, t_img *img, int *w, int *h)
{
	img->cat = (void **)malloc(sizeof(void *) * 4);
	img->cat[0] = mlx_xpm_file_to_image(window->mlx, "assets/w/wr.xpm", w, h);
	img->cat[1] = mlx_xpm_file_to_image(window->mlx, "assets/w/wl.xpm", w, h);
	img->cat[2] = mlx_xpm_file_to_image(window->mlx, "assets/w/wf.xpm", w, h);
	img->cat[3] = mlx_xpm_file_to_image(window->mlx, "assets/w/wb.xpm", w, h);
}