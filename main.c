/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:52:58 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/05 03:54:32 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_window *window;
	t_img	*img;
	window = (t_window *)(malloc(sizeof(t_window)));
	img = (t_img*)malloc(sizeof(t_img));
	
	map_check(ac, av, window);
	
	
	init_window(window,img);
	draw_map(window, img);
	
	//mlx_loop_hook(window->mlx, game_loop, window); //mlx , func, param

	mlx_hook(window->mlx_win, 2, 0, key_handle, window);
	//mlx_hook(window->mlx_win, 17, 0, ft_err, -1);
	mlx_loop(window->mlx);
	return 0;

}

/*static int	game_loop(t_window *a)
{
	long long	now;
	long long	diff_millisecs;

	now = millitimestamp();
	diff_millisecs = now - a->lm;
	static int x = 0;
	
	if (diff_millisecs > 35)
	{
		mlx_clear_window(a->mlx, a->mlx_win);
		mlx_put_image_to_window(a->mlx, a->mlx_win, a->img, x, 0);
		if (x >= 1920 - (700 / 2))
		{
			x = -300;
		}
		else
		{
			x += 10;
		}
		x+=10;
		mlx_destroy_image(a->mlx, a->img);
		a->img = mlx_xpm_file_to_image(a->mlx, a->relative_path, &a->img_width, &a->img_height);
		a->lm = now;
	}
	return (1);
}*/

long long	millitimestamp(void)
{
	struct timeval	timeval;
	long long		microtime;

	gettimeofday(&timeval, NULL);
	microtime = timeval.tv_sec * 1000LL + timeval.tv_usec / 1000;
	return (microtime);
}