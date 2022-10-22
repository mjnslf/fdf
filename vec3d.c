#include "fdf.h"

void	x3d(t_fdf *fdf, t_point *p)
{
	p->rx = (int)((p->x - p->y) * 0.8 * fdf->zoom + fdf->x_rasp);
}

void	y3d(t_fdf *fdf, t_point *p)
{
	p->ry = (int)(p->z * fdf->z_scale + (p->x + p->y) * 0.523599 \
	* fdf->zoom + fdf->y_rasp);
}

void	vec3d(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while ((fdf->points)[i])
	{
		j = 0;
		while (j < fdf->map_w)
		{
			x3d(fdf, &((fdf->points)[i][j]));
			y3d(fdf, &((fdf->points)[i][j]));
			j++;
		}
		i++;
	}
}
