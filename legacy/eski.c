




int	key_event(int keycode, t_data **data)
{
	char		*t;
	char		*nbr;

	find_pos(data, 'P', (*data)->map->str);
	if (keycode == 0 || keycode == 123)
		ft_key_left(data);
	if (keycode == 1 || keycode == 125)
		ft_key_down(data);
	if (keycode == 2 || keycode == 124)
		ft_key_right(data);
	if (keycode == 13 || keycode == 126)
		ft_key_up(data);
	put_image((*data));
	if (keycode == 53)
		map_format_error(-1);
	if ((*data)->move != (*data)->movenew)
		printf_move(data);
	nbr = ft_itoa((*data)->move);
	t = ft_strjoin("MOVE : ", nbr);
	mlx_string_put((*data)->mlx, (*data)->win, 10, 30, 250000 \
	*(*data)->move, t);
	free(nbr);
	free(t);
	return (0);
}








































int	main5(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*relative_path = "assests/azmutjpg.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	int x = 0;
	
	for (int i = 0; i < 24; i++)
	{
		mlx_clear_window(mlx, mlx_win);
		mlx_put_image_to_window(mlx, mlx_win, img, x, 0);
		x += 20;
		printf("%d\n", i);
		sleep(1);
		mlx_destroy_image(mlx, img);
		img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
		
	}
	mlx_loop(mlx);

	//mlx_put_image_to_window(mlx, mlx_win, img, x, 0);
	
	
	return 0;

}