/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 01:37:23 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/05 07:09:57 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_window *window, t_img *img)
{
	draw_background(window, img);
	draw_walls(window, img);
	draw_pec(window, img);
	printf("Adim sayisi: %d\n", window->move_count);
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
				mlx_put_image_to_window(window->mlx, window->mlx_win, img->bg, (j * 64), (i * 64));
			}
			j++;
		}
		//printf("%s",window->map[i]);
		//printf("\n");
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
						(j * 64), (i * 64));
			}
			j++;
		}
		//printf("%s",window->map[i]);
		//printf("\n");
		i++;
	}
}

void	draw_pec(t_window *window, t_img *img)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < window->row)
	{
		j = 0;
		while (j < window->column)
		{
			if (window->map[i][j] == 'P')
			{
				if(img->look == 0)
					mlx_put_image_to_window(window->mlx, window->mlx_win,img->player_right, (j * 64), (i * 64));
				else
					mlx_put_image_to_window(window->mlx, window->mlx_win,img->player_left, (j * 64), (i * 64));
			}
			else if (window->map[i][j] == 'E')
			{
				mlx_put_image_to_window(window->mlx, window->mlx_win, img->exit,
						(j * 64), (i * 64));
			}
			else if (window->map[i][j] == 'C')
			{
				mlx_put_image_to_window(window->mlx, window->mlx_win, img->coin,
						(j * 64), (i * 64));
			}

			j++;
		}
		//printf("%s",window->map[i]);
		//printf("\n");
		i++;
	}
}
