#include "fdf.h"

int	keyboard(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		mlx_destroy_window(fdf->mlx, fdf->win);
		free(fdf->mlx);
		exit(1);
	}
	if (keycode == 123)
		fdf->x_rasp -= 10;
	if (keycode == 124)
		fdf->x_rasp += 10;
	if (keycode == 126)
		fdf->y_rasp -= 10;
	if (keycode == 125)
		fdf->y_rasp += 10;
	if (keycode == 24)
		fdf->zoom += 3;
	if (keycode == 27 && fdf->zoom > 1)
		fdf->zoom -= 3;
	if (keycode == 30)
		fdf->z_scale += 1;
	if (keycode == 33)
		fdf->z_scale -= 1;
	draw(fdf);
	return (0);
}

t_fdf	*param_init(int **map, int num_wid)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->mlx = mlx_init();
	fdf->points = wid_mlx_to_map(map, num_wid);
	fdf->map_w = num_wid;
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->width = WIDTH;
	fdf->height = HEIGHT;
	fdf->x_rasp = WIDTH / 3;
	fdf->y_rasp = HEIGHT / 3;
	fdf->z_scale = -5;
	fdf->zoom = 40;
	return (fdf);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	*fdf;
	int		num_wid;
	char	**map;
	int		**mp;

	if ((!argc) || (argc != 2))
	{
		write(1, "not correct argu!\n", 19);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd > 2)
	{
		map = read_file(fd, &num_wid);
		close(fd);
		mp = matrix(map);
		fdf = param_init(mp, num_wid);
		draw(fdf);
		mlx_key_hook(fdf->win, keyboard, fdf);
		mlx_loop(fdf->mlx);
	}
	else
		write(1, "error!!! only one arg\n", 23);
	return (0);
}
