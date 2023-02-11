/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:42:26 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/11 19:52:21 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check(int ac, char **av, t_window *window)
{
	if (ac < 2)
		ft_err(-1);
	printf("hit\n");
	if (!is_ber(av[1]))
		ft_err(0);
	printf("hit\n");
	if (!is_matris(av[1], window))
		ft_err(1);
	printf("hit\n");
	init_matris(av[1], window);
	printf("hitAA\n");
	if (!is_valid_char(window)) //a da hala sikinti var
		ft_err(2);
	printf("hit\n");
	if (!is_walls_ok(window))
		ft_err(3);
	if (!is_counts_ok(window, window->map))
		ft_err(4);
	if	(!is_valid(window))
		ft_err(5);
	printf("hit\n");
	return (1);
}

int	ft_err(int i)
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

int	is_counts_ok(t_window *window, char **map)
{
	int	i;
	int	j;
	int	pnum;
	int	cnum;
	int	exnum;

	i = 0;
	pnum = 0;
	cnum = 0;
	exnum = 0;

	while (i < window->row)
	{
		j = 0;
		while (j < window->column)
		{
			if (map[i][j] == 'P')
				pnum++;
			if (map[i][j] == 'E')
				exnum++;
			if (map[i][j] == 'C')
				cnum++;
			j++;
		}
		i++;
	}

	if (pnum != 1 || exnum != 1 || cnum <= 0)
		return (0);
	return (1);
}
int	is_valid(t_window	*window)
{
	char	**flooded;
	int	rt;

	flooded = get_copy(window);
	printf("hit i: %d j: %d\n", window->row , window->column);
	printmap(flooded, window->row, window->column);
	ft_flood(window, flooded, get_p_xy(window, 'x'), get_p_xy(window, 'y')); //** bak
	printmap(flooded, window->row, window->column);
	
	rt = ft_is_left(window, flooded);
	freemap(flooded, window->row);
	return (rt);
}
int	get_p_xy(t_window *window, char c)
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
				if (c == 'x')
					return (i);
				if (c == 'y')
					return (j);
			}
			j++;
		}
		i++;
	}
	return (-1);
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
			if (map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == 'C')
			return (0);
			j++;
		}
		i++;
	}
	return(1);
}
void	ft_flood(t_window	*window, char **map, int i, int j)
{
	if (i >= window->row || j >= window->column)
		return;
	if (map[i][j] == '1' || map[i][j] == '2')
		return;
	if (map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == 'C' || map[i][j] == '0')
		map[i][j] = '2';
	//printf("hit i: %d j: %d\n", i , j);
	ft_flood(window, map, i + 1, j);
	ft_flood(window, map, i - 1, j);
	ft_flood(window, map, i, j + 1);
	ft_flood(window, map, i, j - 1);
}

char **get_copy(t_window *window)
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

void	init_matris(char *str, t_window *window)
{
	char	*iter;
	int		fd;
	int		i;

	printf("hitINIT\n");
	fd = open(str, O_RDWR);
	if (!fd)
		return ;
	iter = get_next_line(fd);
	i = 0;
	while (iter) //**//**//**//**//**//**//**//**//**//
	{
		window->map[i] = get_row(iter);
		//printf("%s, %d\n",window->map[i], i);
		free(iter);
		iter = get_next_line(fd);
		i++;
	}
	close(fd);
}

int	is_ber(char *str)
{
	int	len;
	int	fd;

	fd = open(str, O_RDWR);
	if (!fd)
		return (0);
	len = ft_strlen(str);
	len--;
	if (str[len - 2] == 'b' && str[len - 1] == 'e' && str[len] == 'r')
	{
		if (str[len - 3] == '.' && str[len - 4] != '\0')
			return (1);
	}
	close(fd);
	return (0);
}

int	is_matris(char *str, t_window *window)
{
	int		fd;
	char	*iter;

	fd = open(str, O_RDWR);
	if (!fd)
		return (0);
	iter = get_next_line(fd);
	window->row = 0;
	window->column = ft_strlen(iter) - 1; //minus \n
	//printf("iter = $%s$ col: %d, row: %d\n",iter, column, row);
	while (iter)
	{
		window->row++;
		if (ft_strlen(iter) != window->column + 1)
		{
			//printf("%s\n", iter);
			return (0);
		}
		free(iter);
		iter = get_next_line(fd);
	}
	window->map = (char **)malloc(sizeof(char *) * window->row);
	window->window_width = window->column * IMG;
	window->window_height = window->row * IMG;
	//printf("col: %d, row: %d\n", column, row);
	close(fd); //??
	return (window->row);
}
