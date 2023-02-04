/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:50:23 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/05 02:19:17 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "gnl/get_next_line.h"

# include <unistd.h>
# include <stdio.h> //
# include <sys/time.h> //
# include <fcntl.h> 
# include <stdlib.h> //


typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	void	*img;

	void	*bg;
	void	*wall;
	
	char	*relative_path;

	int		img_width; //
	int		img_height; //
	long long lm; //time

	int		window_width;
	int		window_height;
	int		row;
	int		column;
	char	**map;

}	t_window;


static int	game_loop(t_window *a);
long long	millitimestamp(void);
void	init_window(t_window *window);


//checks

int	map_check(int ac, char **av, t_window *window);
int	is_ber(char *str);
int	is_valid_char(t_window *window);
int	is_walls_ok(t_window *window);
void	init_matris(char *str, t_window *window);
int	is_pec(char c);
int	is_matris(char *str, t_window *window);
void ft_err(int i);


//check utils

char	*get_row(char *str);

//draw map

void	draw_background(t_window	*window);
void	draw_map(t_window *window);
void	draw_walls(t_window	*window);



#endif