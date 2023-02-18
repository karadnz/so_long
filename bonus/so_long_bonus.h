/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:50:23 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/18 17:56:04 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG 100 

# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"

# include <unistd.h>
//# include <stdio.h> //
# include <sys/time.h> //
# include <fcntl.h> 
# include <stdlib.h> //



typedef struct s_enemy
{
	int	x;
	int	y;
	int	eindex;
	int	elook;
	
}	t_enemy;


typedef struct s_img
{
	void	*bg;
	void	*wall;
	void	*exit;
	void	*exit_open;
	void	*hearth;
	void	*paw;
	void	*cmini;
	
	void	**hbar;
	void	**coin;
	void	**cat;
	void	**nums;
	void	**enemy;
	t_enemy	**enemies;

	int		img_width;
	int		img_height;
	int		look;
	int		cindex;
	int		eindex;
}	t_img;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;

	//void	*relative_path;
	//void	*bg;
	//void 	*wall;
	

	int		img_width; //
	int		img_height; //
	long long ft; //time
	long long dt;

	int		window_width;
	int		window_height;
	int		row;
	int		column;
	char	**map;

	int		move_count;
	int		ccount;
	int		encount;

	int		x;
	int		y;
	int		health;

	int	pnum;
	int	cnum;
	int	exnum;

}	t_window;






int	game_loop(t_window *a);
long long	millitimestamp(void);
void	init_window(t_window *window, t_img *img);
int	is_dead(t_window *window, t_img *img);

void	free_arr(void **arr, int size);


//enemy
void	get_en_count(t_window *window);
void	get_e_xy(t_window *window);
void	enemy_move(t_window *window, t_img *img);
void	update_eindex(t_window *window);

void	enemy_move_dir(t_window *window, t_enemy *enemy, int x, int y);

void	draw_enemies(t_window *window, t_img *img); //draw

//init
void	init_window(t_window *window, t_img *img);
void	init_coin(t_window *window, t_img *img, int *w, int *h); //free
void	init_hbar(t_window *window, t_img *img, int *w, int *h);
void	init_nums(t_window *window, t_img *img, int *w, int *h);
void	draw_nums(t_window *window, t_img *img);
void	init_enemy(t_window *window, t_img *img, int *w, int *h);
void	init_player(t_window *window, t_img *img, int *w, int *h);
void	init_wnums(t_window *window, t_img *img);

void	init_enemy_left(t_window *window, t_img *img, int *w, int *h);

//checks

int	map_check(int ac, char **av, t_window *window);
int	is_ber(char *str);
int	is_valid_char(t_window *window);
int	is_walls_ok(t_window *window);
void	init_matris(char *str, t_window *window);
int	is_matris(char *str, t_window *window);
int	is_valid(t_window	*window);
void	ft_flood(t_window	*window, char **map, int i, int j);
char **get_copy(t_window *window);
int	ft_is_left(t_window *window, char **map);
int	get_p_xy(t_window *window, char c);
int	is_counts_ok(t_window *window, char **map);


//check utils

char	*get_row(char *str);
int	is_pec(char c);
void	printmap(char **map, int row, int col);

//free exit
int	ft_err(int i, t_window *window);
void	free_window(t_window *window);
void	freemap(char **map, int row);
void	free_img_arr(t_window	*window, void **arr, int size);

//draw map

void	draw_background(t_window *window , t_img *img);
void	draw_map(t_window *window , t_img *img);
void	draw_walls(t_window *window , t_img *img);
void	draw_pec(t_window *window , t_img *img);
void	draw_nums(t_window *window, t_img *img);


//handle

int key_handle(int keycode, t_window *window);
void	down_handle(t_window *window);
void	up_handle(t_window *window);
void	right_handle(t_window *window);
void	left_handle(t_window *window);
int	can_exit(t_window *window);
void	try_exit(t_window *window);

//libftutils
void	ft_putnbr_fd(int n, int fd);



#endif