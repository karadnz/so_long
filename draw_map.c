/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 01:37:23 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/16 14:50:27 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_window *window, t_img *img)
{
	draw_background(window, img);
	draw_walls(window, img);
	mlx_put_image_to_window(window->mlx, window->mlx_win,
		img->hbar[window->health], 10, 10);
	draw_nums(window, img);
	draw_pec(window, img);
	draw_enemies(window, img);
	printf("Adim sayisi: %d\n", window->move_count);
}

void	draw_nums(t_window *window, t_img *img)
{
	int	s;
	int	c;

	s = window->move_count;
	c = window->ccount;
	mlx_put_image_to_window(window->mlx, window->mlx_win, img->paw, (7.5 * 41),
		(IMG / 8));
	mlx_put_image_to_window(window->mlx, window->mlx_win, img->nums[(s / 1000)
		% 10], (8.5 * 41), (IMG / 8));
	mlx_put_image_to_window(window->mlx, window->mlx_win, img->nums[(s / 100)
		% 10], (9.5 * 41), (IMG / 8));
	mlx_put_image_to_window(window->mlx, window->mlx_win, img->nums[(s / 10)
		% 10], (10.5 * 41), (IMG / 8));
	mlx_put_image_to_window(window->mlx, window->mlx_win, img->nums[s % 10],
		(11.5 * 41), (IMG / 8));
	mlx_put_image_to_window(window->mlx, window->mlx_win, img->cmini, (7.5
			* 41), (IMG / 1.8));
	mlx_put_image_to_window(window->mlx, window->mlx_win, img->nums[(c / 1000)
		% 10], (8.5 * 41), (IMG / 1.8));
	mlx_put_image_to_window(window->mlx, window->mlx_win, img->nums[(c / 100)
		% 10], (9.5 * 41), (IMG / 1.8));
	mlx_put_image_to_window(window->mlx, window->mlx_win, img->nums[(c / 10)
		% 10], (10.5 * 41), (IMG / 1.8));
	mlx_put_image_to_window(window->mlx, window->mlx_win, img->nums[c % 10],
		(11.5 * 41), (IMG / 1.8));
}

void	draw_background(t_window *window, t_img *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < window->row)
	{
		j = 0;
		while (j < window->column)
		{
			if (window->map[i][j] == '0' || 1)
			{
				mlx_put_image_to_window(window->mlx, window->mlx_win, img->bg,
					(j * IMG), (i * IMG));
			}
			j++;
		}
		i++;
	}
}

void	draw_walls(t_window *window, t_img *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < window->row)
	{
		j = 0;
		while (j < window->column)
		{
			if (window->map[i][j] == '1')
			{
				mlx_put_image_to_window(window->mlx, window->mlx_win, img->wall,
					(j * IMG), (i * IMG));
			}
			j++;
		}
		i++;
	}
}

void	draw_pec(t_window *window, t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < window->row)
	{
		j = 0;
		while (j < window->column)
		{
			if (window->map[i][j] == 'E')
			{
				if (can_exit(window))
					mlx_put_image_to_window(window->mlx, window->mlx_win,
						img->exit_open, (j * IMG), (i * IMG));
				else
					mlx_put_image_to_window(window->mlx, window->mlx_win,
						img->exit, (j * IMG), (i * IMG));
			}
			else if (window->map[i][j] == 'C')
				mlx_put_image_to_window(window->mlx, window->mlx_win,
					img->coin[img->cindex], (j * IMG), (i * IMG));
			j++;
		}
		i++;
	}
}
