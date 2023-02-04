#include "mlx/mlx.h"
#include<unistd.h>
#include <stdio.h>
# include <sys/time.h>
# include <fcntl.h>
# include <stdlib.h>



int	main2(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);

	return 0;
}

long long	millitimestamp(void)
{
	struct timeval	timeval;
	long long		microtime;

	gettimeofday(&timeval, NULL);
	microtime = timeval.tv_sec * 1000LL + timeval.tv_usec / 1000;
	return (microtime);
}

/*int asdas()
{
	mlx_clear_window(mlx, mlx_win);
	mlx_put_image_to_window(mlx, mlx_win, img, x, 0);
	x += 20;
	printf("%d\n", i);
	sleep(1);
	mlx_destroy_image(mlx, img);
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
}*/

typedef struct s_struct
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	long long lm;

}t_struct;

static int	azmut(t_struct *a)
{
	long long	now;
	long long	diff_millisecs;

	now = millitimestamp();
	diff_millisecs = now - a->lm;
	static int x = 0;
	if (diff_millisecs > 35)
	{
		mlx_clear_window(a->mlx, a->mlx_win);
		mlx_put_image_to_window(a->mlx, a->mlx_win, a->img, x, 0);
		if (x >= 1920 - (700 / 2))
		{
			x = -300;
		}
		else
		{
			x += 10;
		}
		x+=10;
		mlx_destroy_image(a->mlx, a->img);
		a->img = mlx_xpm_file_to_image(a->mlx, a->relative_path, &a->img_width, &a->img_height);
		a->lm = now;
	}
	return (1);
}

int	main(void)
{
	t_struct *a;

	a = malloc(sizeof(t_struct));
	a->relative_path = "./azmutjpg.xpm";

	a->mlx = mlx_init();
	a->mlx_win = mlx_new_window(a->mlx, 1920, 1080, "Hello world!");
	a->img = mlx_xpm_file_to_image(a->mlx, a->relative_path, &a->img_width, &a->img_height);
	//mlx_put_image_to_window(a->mlx, a->mlx_win, a->img, 0, 0);

	mlx_loop_hook(a->mlx, azmut, a);
	mlx_loop(a->mlx);
	return 0;

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
