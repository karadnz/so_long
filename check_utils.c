/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 23:24:35 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/18 20:59:20 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//minus \n
//close fd bak
//printf("iter = $%s$ col: %d, row: %d\n", iter, window->column, window->row);
//printf("%s, %d\n", iter, ft_strlen(iter));
//printf(" col: %d, row: %d\n", window->column, window->row);
int	is_matris(char *str, t_window *window)
{
	int		fd;
	char	*iter;

	fd = open(str, O_RDWR);
	if (!fd)
		return (0);
	iter = get_next_line(fd);
	window->row = 0;
	window->column = ft_strlen(iter) - 1;
	while (iter)
	{
		window->row++;
		if (ft_strlen(iter) != (size_t)window->column + 1)
		{
			free(iter);
			return (0);
		}
		free(iter);
		iter = get_next_line(fd);
	}
	window->map = (char **)malloc(sizeof(char *) * window->row);
	window->window_width = window->column * IMG;
	window->window_height = window->row * IMG;
	close(fd);
	return (window->row);
}

//**//**//**//**//**//**//**//**//**//
//printf("%s, %d\n",window->map[i], i);
void	init_matris(char *str, t_window *window)
{
	char	*iter;
	int		fd;
	int		i;

	fd = open(str, O_RDWR);
	if (!fd)
		return ;
	iter = get_next_line(fd);
	i = 0;
	while (iter)
	{
		window->map[i] = get_row(iter);
		free(iter);
		iter = get_next_line(fd);
		i++;
	}
	close(fd);
}

int	is_valid_char(t_window *window)
{
	int	i;
	int	j;

	i = 0;
	while (i < window->row)
	{
		j = 0;
		while (j < window->column)
		{
			if (!is_pec(window->map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_walls_ok(t_window *window)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = window->map;
	while (j < window->column)
	{
		if (map[0][j] != '1' || map[window->row - 1][j] != '1')
			return (0);
		j++;
	}
	while (i < window->row)
	{
		if (map[i][0] != '1' || map[i][window->column - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_counts_ok(t_window *window, char **map)
{
	int	i;
	int	j;

	i = 0;
	window->pnum = 0;
	window->cnum = 0;
	window->exnum = 0;
	while (i < window->row)
	{
		j = 0;
		while (j < window->column)
		{
			if (map[i][j] == 'P')
				window->pnum++;
			if (map[i][j] == 'E')
				window->exnum++;
			if (map[i][j] == 'C')
				window->cnum++;
			j++;
		}
		i++;
	}
	if (window->pnum != 1 || window->exnum != 1 || window->cnum <= 0)
		return (0);
	return (1);
}
