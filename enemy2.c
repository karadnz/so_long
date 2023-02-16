/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:33:24 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/16 17:23:51 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_enemies(t_window *window, t_img *img)
{
	int		i;
	int		x;
	int		y;
	t_enemy	*enemy;
	char	**map;
	printf("HIT look %d xy: %d %d \n \n", img->look, window->y, window->x);
	i = 0;
	map = window->map;
	mlx_put_image_to_window(window->mlx, window->mlx_win, img->cat[img->look],(window->y * IMG), (window->x * IMG));
	printf("HIT look \n \n");
	printf("HIT look \n \n");
	printf("HIT look \n \n");
	printf("HIT look \n \n");
	
	while (i < window->encount)
	{
		enemy = img->enemies[i];
		printf("eindex: %d elook: %d\n",img->eindex, enemy->elook);
		x = enemy->x;
		y = enemy->y;
		mlx_put_image_to_window(window->mlx, window->mlx_win,
			img->enemy[img->eindex + enemy->elook], (y * IMG), (x * IMG));
		i++;
	}
}