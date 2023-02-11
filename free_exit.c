/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:03:43 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/11 20:37:21 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_err(int i, t_window *window)
{
	if (i == -1)
		write(1, "Error at argc", 13);
	else if (i == 0)
		write(1, "Error at .ber\n", 14);
	else if (i == 1)
		write(1, "Error at is matris\n", 19);
	else if (i == 2)
		write(1, "Error at valid char\n", 20);
	else if (i == 3)
		write(1, "Error at walls ok\n", 18);
	else if (i == 4)
		write(1, "invalid number of p,e,c!\n", 29);
	else if (i == 5)
		write(1, "flood fail\n", 11);
	else
		write(1, "cikis!\n",7);
	
	exit(1);
}

void	free_window(t_window *window)
{
	free(window->mlx);
	free(window->mlx_win);
	free(window->img); //**
	free(window->img->bg);
	free(window->img->wall);
	free(window->img->coin);
	free(window->img->player_right);
	free(window->img->player_left);
	free(window->img->exit);
	free(window->img->exit);
	freemap(window->map, window->row);
	free(window);
}

void	freemap(char **map, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(map[i]);
		i++;
	}
	free(map);
}