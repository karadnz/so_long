/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:52:58 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/11 19:27:45 by mkaraden         ###   ########.fr       */
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
	mlx_loop(window->mlx);
	return (0);
}
