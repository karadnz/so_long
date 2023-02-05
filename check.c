/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:42:26 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/05 07:01:27 by mkaraden         ###   ########.fr       */
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
	else
		write(1, "cikis!\n",7);
	exit(1);
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
	j = 0;
	while (i < window->row)
	{
		j = 0;
		while (j < window->column)
		{
			if (!is_pec(window->map[i][j]))
			{
				//printf("$%c$",window->map[i][j]);
				//printf("$i:%d  j:%d, str:%s,$",i,j,window->map[i]);
				return (0);
			}
			j++;
		}
		//printf("%s",window->map[i]);
		//printf("\n");
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
	int		column;
	int		row;
	int		fd;
	char	*iter;
	int		i;

	fd = open(str, O_RDWR);
	if (!fd)
	{
		//printf("FD hit\n");
		return (0);
	}
	row = 0;
	iter = get_next_line(fd);
	column = ft_strlen(iter);
	i = 0;
	while (iter)
	{
		row++;
		if (ft_strlen(iter) != column)
		{
			//printf("%s\n", iter);
			return (0);
		}
		free(iter);
		iter = get_next_line(fd);
		i++;
	}
	window->column = column - 1; //minus \n
	window->row = row;
	window->map = (char **)malloc(sizeof(char *) * i);
	window->window_width = (column - 1) * 64;
	window->window_height = row * 64;
	close(fd);
	return (i);
}
