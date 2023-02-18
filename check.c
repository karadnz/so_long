/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:42:26 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/18 23:57:33 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check(int ac, char **av, t_window *window)
{
	if (ac < 2)
		ft_err(-1, window);
	if (!is_ber(av[1]))
		ft_err(0, window);
	if (!is_matris(av[1], window))
		ft_err(1, window);
	init_matris(av[1], window);
	if (!is_valid_char(window))
		ft_err(2, window);
	if (!is_walls_ok(window))
		ft_err(3, window);
	if (!is_counts_ok(window, window->map))
		ft_err(4, window);
	if (!is_valid(window))
		ft_err(5, window);
	return (1);
}

//printf("hit i: %d j: %d\n", window->row, window->column);
//printmap(flooded, window->row, window->column);
int	is_valid(t_window *window)
{
	char	**flooded;
	int		rt;

	flooded = get_copy(window);
	ft_flood(window, flooded, get_p_xy(window, 'x'), get_p_xy(window, 'y'));
	rt = ft_is_left(window, flooded);
	freemap(flooded, window->row);
	return (rt);
}

char	**get_copy(t_window *window)
{
	char	**rt;
	int		i;
	int		j;

	rt = (char **)malloc(sizeof(char *) * window->row);
	i = 0;
	while (i < window->row)
	{
		j = 0;
		rt[i] = (char *)malloc(sizeof(char) * window->column);
		while (j < window->column)
		{
			rt[i][j] = window->map[i][j];
			j++;
		}
		i++;
	}
	return (rt);
}

//printf("hit i: %d j: %d\n", i , j);
void	ft_flood(t_window *window, char **map, int i, int j)
{
	if (i >= window->row || j >= window->column)
		return ;
	if (map[i][j] == 'E')
		map[i][j] = '1';
	if (map[i][j] == '1' || map[i][j] == '2')
		return ;
	if (map[i][j] == 'P' || map[i][j] == 'C'
		|| map[i][j] == '0')
		map[i][j] = '2';
	ft_flood(window, map, i + 1, j);
	ft_flood(window, map, i - 1, j);
	ft_flood(window, map, i, j + 1);
	ft_flood(window, map, i, j - 1);
}

int	ft_is_left(t_window *window, char **map)
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
			if (map[i][j] == 'P' || map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
