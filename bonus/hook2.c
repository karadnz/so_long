/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:31:31 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/18 17:23:52 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	try_exit(t_window *window)
{
	if (can_exit(window))
	{
		window->move_count++;
		draw_map(window, window->img);
		free_window(window);
		ft_err(7, window);
	}
}

int	can_exit(t_window *window)
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
			if (window->map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
