/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 03:29:31 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/11 21:19:06 by mkaraden         ###   ########.fr       */
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
		ft_err(-1, window);
	draw_map(window, window->img);
	return (1);
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

	map = window->map;
	x = window->x;
	y = window->y;
	if (x + 1 < window->row)
	{
		if (map[x + 1][y] == 'E')
			try_exit(window);
		if (map[x + 1][y] != '1' && map[x + 1][y] != 'E')
		{
			map[x + 1][y] = 'P';
			map[x][y] = '0';
			window->move_count++;
			window->x++;
			return ;
		}
	}
	return ;
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
			map[x][y + 1] = 'P';
			map[x][y] = '0';
			window->move_count++;
			window->y++;
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

	map = window->map;
	x = window->x;
	y = window->y;
	if (x + 1 < window->row)
	{
		if (map[x - 1][y] == 'E')
			try_exit(window);
		if (map[x - 1][y] != '1' && map[x - 1][y] != 'E')
		{
			map[x - 1][y] = 'P';
			map[x][y] = '0';
			window->move_count++;
			window->x--;
			return ;
		}
	}
	return ;
}

void	try_exit(t_window *window)
{
	if (can_exit(window))
	{
		window->move_count++;
		draw_map(window, window->img);
		free_window(window);
		exit(1);
	}
}

int	can_exit(t_window *window)
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
			if (window->map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*void	down_handle2(t_window *window)
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
			if (window->map[i][j] == 'P')
			{
				if (i + 1 < window->row)
				{
					if (window->map[i + 1][j] == 'E')
					{
						if (can_exit(window))
							exit(1);
					}
					if (window->map[i + 1][j] != '1' && window->map[i
						+ 1][j] != 'E')
					{
						window->map[i + 1][j] = 'P';
						window->map[i][j] = '0';
						window->move_count++;
						return ;
					}
				}
			}
			j++;
		}
		i++;
	}
	printf("DOWN\n\n");
}*/
/*
void	up_handle(t_window *window)
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
			if (window->map[i][j] == 'P')
			{
				if (i - 1 > 0)
				{
					if (window->map[i - 1][j] == 'E')
					{
						if (can_exit(window))
							exit(1); //*
					}
					if (window->map[i - 1][j] != '1' && window->map[i
						- 1][j] != 'E')
					{
						window->map[i - 1][j] = 'P';
						window->map[i][j] = '0';
						window->move_count++;
						return ;
					}
				}
			}
			j++;
		}
		i++;
	}
	printf("UP\n\n");
}

void	right_handle(t_window *window)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	window->img->look = 0;
	while (i < window->row)
	{
		j = 0;
		while (j < window->column)
		{
			if (window->map[i][j] == 'P')
			{
				if (j + 1 < window->column)
				{
					if (window->map[i][j + 1] == 'E')
					{
						if (can_exit(window))
							exit(1);
					}
					if (window->map[i][j + 1] != '1' && window->map[i][j
						+ 1] != 'E')
					{
						window->map[i][j + 1] = 'P';
						window->map[i][j] = '0';
						window->move_count++;
						return ;
					}
				}
			}
			j++;
		}
		i++;
	}
	printf("RIGHT\n\n");
}

void	left_handle(t_window *window)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	window->img->look = 1;
	while (i < window->row)
	{
		j = 0;
		while (j < window->column)
		{
			if (window->map[i][j] == 'P')
			{
				if (j - 1 > 0)
				{
					if (window->map[i][j - 1] == 'E')
					{
						if (can_exit(window))
						{
							window->move_count++;
							printf("Adim sayisi: %d\n", window->move_count);
							exit(1);
						}	
					}
					else if (window->map[i][j - 1] != '1')
					{
						window->map[i][j - 1] = 'P';
						window->map[i][j] = '0';
						window->move_count++;
						return ;
					}
				}
			}
			j++;
		}
		i++;
	}
	printf("LEFT\n\n");
}
*/
