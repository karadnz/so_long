/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:52:58 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/14 14:00:17 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static int	game_loop(t_window *window)
{
	long long	now;
	long long	diff_millisecs;

	now = millitimestamp();
	diff_millisecs = now - window->lm;
	static int x = 0;
	
	if (diff_millisecs > 50)
	{
		window->img->cindex++;
		if (window->img->cindex == 6)
			window->img->cindex = 0;
		window->lm = now;
	}
	draw_map(window, window->img);
	return (1);
}

long long	millitimestamp(void)
{
	struct timeval	timeval;
	long long		microtime;

	gettimeofday(&timeval, NULL);
	microtime = timeval.tv_sec * 1000LL + timeval.tv_usec / 1000;
	return (microtime);
}
