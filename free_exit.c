/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:03:43 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/18 17:12:12 by mkaraden         ###   ########.fr       */
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
	else if (i == 6)
		write(1, "you died\n", 10);
	else if (i == 7)
		write(1, "you won\n", 8);
	else
		write(1, "cikis!\n", 7);
	system("leaks so_long");
	exit(1);
}

//free(window->mlx->font);
	//free(window->mlx); //******
	//free(window->mlx_win);
	//free(window);
void	free_window(t_window *window)
{
	mlx_destroy_image(window->mlx, window->img->bg);
	mlx_destroy_image(window->mlx, window->img->wall);
	mlx_destroy_image(window->mlx, window->img->exit);
	mlx_destroy_image(window->mlx, window->img->exit_open);
	mlx_destroy_image(window->mlx, window->img->hearth);
	mlx_destroy_image(window->mlx, window->img->paw);
	mlx_destroy_image(window->mlx, window->img->cmini);
	free_img_arr(window, window->img->hbar, 4);
	free_img_arr(window, window->img->coin, 6);
	free_img_arr(window, window->img->cat, 4);
	free_img_arr(window, window->img->nums, 10);
	free_img_arr(window, window->img->enemy, 22);
	free_arr((void **)window->img->enemies, window->encount);
	free(window->img);
	free_arr(window->map, window->row);
	mlx_destroy_window(window->mlx, window->mlx_win);
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

void	free_img_arr(t_window	*window, void **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		mlx_destroy_image(window->mlx, arr[i]);
		i++;
	}
	free(arr);
}

void	free_arr(void **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
