/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:33:24 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/16 17:37:03 by mkaraden         ###   ########.fr       */
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

	i = 0;
	map = window->map;
	mlx_put_image_to_window(window->mlx, window->mlx_win, img->cat[img->look],
		(window->y * IMG), (window->x * IMG));
	while (i < window->encount)
	{
		enemy = img->enemies[i];
		x = enemy->x;
		y = enemy->y;
		mlx_put_image_to_window(window->mlx, window->mlx_win,
			img->enemy[img->eindex + enemy->elook], (y * IMG), (x * IMG));
		i++;
	}
}
