/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 01:37:23 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/05 02:20:00 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_window *window)
{
	draw_background(window);
	draw_walls(window);
}

void	draw_background(t_window	*window)
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
			if(window->map[i][j] == '0')
			{
				printf("HIT\n\n\n\n");
				mlx_put_image_to_window(window->mlx, window->mlx_win, window->bg, (j * 64), (i * 64));

			}
			
			j++;
		}
		printf("%s",window->map[i]);
		printf("\n");
		i++;
	}
}

void	draw_walls(t_window	*window)
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
			if(window->map[i][j] == '1')
			{
				printf("HIT\n\n\n\n");
				mlx_put_image_to_window(window->mlx, window->mlx_win, window->wall, (j * 64), (i * 64));

			}
			
			j++;
		}
		printf("%s",window->map[i]);
		printf("\n");
		i++;
	}
}