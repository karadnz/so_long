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