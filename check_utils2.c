/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:55:01 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/16 16:21:31 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// len without \n
char	*get_row(char *str)
{
	int		i;
	char	*rt;
	int		len;

	len = ft_strlen(str) - 1;
	rt = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		rt[i] = str[i];
		i++;
	}
	rt[i] = '\0';
	return (rt);
}

int	is_pec(char c)
{
	if (c == '1' || c == '0' || c == 'P')
		return (1);
	if (c == 'E' || c == 'C' || c == 'X')
		return (1);
	return (0);
}

void	printmap(char **map, int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
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
