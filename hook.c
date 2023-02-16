/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 03:29:31 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/16 19:08:34 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handle(int keycode, t_window *window)
{
	if (keycode == 0 || keycode == 123)
		left_handle(window);
	if (keycode == 1 || keycode == 125)
		down_handle(window);
	if (keycode == 2 || keycode == 124)
		right_handle(window);
	if (keycode == 13 || keycode == 126)
		up_handle(window);
	if (keycode == 53)
		ft_err(6, window);
	return (1);
}

void	right_handle(t_window *window)
{
	int		x;
	int		y;
	char	**map;

	window->img->look = 0;
	map = window->map;
	x = window->x;
	y = window->y;
	if (x + 1 < window->row)
	{
		if (map[x][y + 1] == 'E')
			try_exit(window);
		if (map[x][y + 1] != '1' && map[x][y + 1] != 'E')
		{
			if (map[x][y + 1] == 'C')
				window->ccount++;
			map[x][y + 1] = 'P';
			map[x][y] = '0';
			window->move_count++;
			window->y++;
			return ;
		}
	}
	return ;
}

void	left_handle(t_window *window)
{
	int		x;
	int		y;
	char	**map;

	window->img->look = 1;
	map = window->map;
	x = window->x;
	y = window->y;
	if (x + 1 < window->row)
	{
		if (map[x][y - 1] == 'E')
			try_exit(window);
		if (map[x][y - 1] != '1' && map[x][y - 1] != 'E')
		{
			if (map[x][y - 1] == 'C')
				window->ccount++;
			map[x][y - 1] = 'P';
			map[x][y] = '0';
			window->move_count++;
			window->y--;
			return ;
		}
	}
	return ;
}

void	down_handle(t_window *window)
{
	int		x;
	int		y;
	char	**map;

	window->img->look = 2;
	map = window->map;
	x = window->x;
	y = window->y;
	if (x + 1 < window->row)
	{
		if (map[x + 1][y] == 'E')
			try_exit(window);
		if (map[x + 1][y] != '1' && map[x + 1][y] != 'E')
		{
			if (map[x + 1][y] == 'C')
				window->ccount++;
			map[x + 1][y] = 'P';
			map[x][y] = '0';
			window->move_count++;
			window->x++;
			return ;
		}
	}
	return ;
}

void	up_handle(t_window *window)
{
	int		x;
	int		y;
	char	**map;

	window->img->look = 3;
	map = window->map;
	x = window->x;
	y = window->y;
	if (x + 1 < window->row)
	{
		if (map[x - 1][y] == 'E')
			try_exit(window);
		if (map[x - 1][y] != '1' && map[x - 1][y] != 'E')
		{
			if (map[x - 1][y] == 'C')
				window->ccount++;
			map[x - 1][y] = 'P';
			map[x][y] = '0';
			window->move_count++;
			window->x--;
			return ;
		}
	}
	return ;
}
