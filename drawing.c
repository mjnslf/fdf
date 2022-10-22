#include "fdf.h"

void	drawing(t_fdf *fdf)
{
	int	y;
	int	x;

	y = 0;
	while ((fdf->points)[y])
	{
		x = 0;
		while (x < fdf->map_w)
		{
			if (x < fdf->map_w - 1)
				draw_line(fdf, (fdf->points)[y][x], (fdf->points)[y][x + 1]);
			if ((fdf->points)[y + 1])
				draw_line(fdf, (fdf->points)[y][x], (fdf->points)[y + 1][x]);
			x++;
		}
		y++;
	}
}

int	draw(t_fdf *fdf)
{
	mlx_img_clear(fdf);
	vec3d(fdf);
	drawing(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	return (0);
}

void	draw_line(t_fdf *fdf, t_point a, t_point b)
{
	fdf->step_x = abs(b.rx - a.rx);
	fdf->step_y = abs(b.ry - a.ry);
	fdf->deltaerr = fdf->step_x - fdf->step_y;
	while (a.rx != b.rx || a.ry != b.ry)
	{
		mlx_pix_put(fdf, a.rx, a.ry, color(b.z));
		if ((fdf->deltaerr * 2) > -(fdf->step_y))
		{
			fdf->deltaerr -= fdf->step_y;
			if (a.rx < b.rx)
				a.rx += 1;
			else
				a.rx += (-1);
		}
		if ((fdf->deltaerr * 2) < fdf->step_x)
		{
			fdf->deltaerr += fdf->step_x;
			if (a.ry < b.ry)
				a.ry += 1;
			else
				a.ry += (-1);
		}
	}
}
