/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:52:58 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/18 21:25:47 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_window	*window;
	t_img		*img;

	window = (t_window *)(malloc(sizeof(t_window)));
	img = (t_img *)malloc(sizeof(t_img));
	map_check(ac, av, window);
	init_window(window, img);
	draw_map(window, img);
	mlx_hook(window->mlx_win, 2, 0, key_handle, window);
	mlx_hook(window->mlx_win, 17, 0, ft_err, window);
	mlx_loop_hook(window->mlx, game_loop, window);
	mlx_loop(window->mlx);
	return (0);
}

int	game_loop(t_window *window)
{
	long long	now;

	now = millitimestamp();
	if (now - window->ft > 70)
	{
		window->ft = now;
		window->img->cindex++;
		window->img->eindex++;
		if (window->img->cindex == 6)
			window->img->cindex = 0;
		if (window->img->eindex == 10)
			enemy_move(window, window->img);
		draw_map(window, window->img);
		if (is_dead(window, window->img) && now - window->dt > 2500)
		{
			window->health--;
			if (window->health == 0)
				ft_err(6, window);
			window->dt = now;
		}
	}
	return (1);
}

int	is_dead(t_window *window, t_img *img)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < window->encount)
	{
		x = img->enemies[i]->x;
		y = img->enemies[i]->y;
		if (x == window->x && y == window->y)
			return (1);
		i++;
	}
	return (0);
}

long long	millitimestamp(void)
{
	struct timeval	timeval;
	long long		microtime;

	gettimeofday(&timeval, NULL);
	microtime = timeval.tv_sec * 1000LL + timeval.tv_usec / 1000;
	return (microtime);
}
