/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:23:36 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/16 14:50:19 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_en_count(t_window *window)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	window->encount = 0;
	while (i < window->row)
	{
		j = 0;
		while (j < window->column)
		{
			if (window->map[i][j] == 'X')
					window->encount++;
			j++;
		}
		i++;
	}
}

void	get_e_xy(t_window *window)
{
	printf("xxx\n");
	int	i;
	int	j;
	int	e;
	char	**map;

	i = 0;
	j = 0;
	e = 0;
	map = window->map;
	while (i < window->row)
	{
		j = 0;
		while (j < window->column)
		{
			if (window->map[i][j] == 'X')
			{
				printf("%d\n",window->encount);
				window->img->enemies[e]->x = i;
				window->img->enemies[e]->y = j;
				window->img->enemies[e]->elook = 0;
				window->img->enemies[e]->eindex = 0;
				e++;
				printf("xxx\n");
			}
			j++;
		}
		i++;
	}
}

void	enemy_move(t_window *window, t_img *img)
{
	int	i;
	int	x;
	int	y;
	t_enemy *enemy;
	char	**map;

	i = 0;
	map = window->map;
	while(i < window->encount)
	{
		enemy = img->enemies[i];
		x = enemy->x;
		y = enemy->y;
		

		if (enemy->elook == 0)
		{
			if (map[x][y + 1] != '0' && map[x][y + 1] != 'P')
			{
				enemy->elook = 11;
			}
			else
			{
				map[x][y + 1] = 'X';
				map[x][y] = '0';
				enemy->y++;
			}

		}

		else if (enemy->elook == 11)
		{
			if (map[x][y - 1] != '0' && map[x][y - 1] != 'P')
			{
				enemy->elook = 0;
			}
			else
			{
				map[x][y - 1] = 'X';
				map[x][y] = '0';
				enemy->y--;
			}

		}

		i++;
		
	
	}
	window->img->eindex = 0;
}

void	update_eindex(t_window *window)
{
	int	i;
	char	**map;

	i = 0;
	map = window->map;
	while(i < window->encount)
	{
		window->img->enemies[i]->eindex++;
		if (window->img->enemies[i]->eindex == 10)
		{
			window->img->enemies[i]->eindex = 0;
		}
		i++;
	}
}

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