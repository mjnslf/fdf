#include "fdf.h"

int	*ft_read(char *str)
{
	int				*from;
	register int	i;
	register int	j;

	from = (int *)malloc(sizeof(int) * gnl_strlen(str));
	i = 0;
	j = 0;
	from[i++] = ft_atoi(str);
	while (gnl_strlen(&(str[j])) != 0)
	{
		while (str[j] != ' ' && str[j])
			j++;
		while (str[j] == ' ')
			j++;
		from[i++] = ft_atoi(&(str[j]));
	}
	return (from);
}

int	**matrix(char **map)
{
	int		**int_map;
	int		point[3];

	point[1] = 0;
	point[2] = 0;
	while (map[point[1]])
		point[1]++;
	int_map = (int **)malloc((point[1] + 1) * sizeof(int *));
	while (point[2] < point[1])
	{
		int_map[point[2]] = ft_read(map[point[2]]);
		point[2]++;
	}
	int_map[point[2]] = NULL;
	return (int_map);
}

t_point	**wid_mlx_to_map(int **map, int m_width)
{
	t_point	**from;
	t_point	perem;

	while (map[perem.i])
		perem.i++;
	from = (t_point **)malloc(sizeof(t_point *) * (perem.i + 1));
	perem.j = 0;
	while (perem.j < perem.i)
	{
		perem.k = 0;
		from[perem.j] = (t_point *)malloc(sizeof(t_point) * m_width);
		while (perem.k < m_width)
		{
			from[perem.j][perem.k].x = perem.k - m_width / 3;
			from[perem.j][perem.k].y = perem.j - perem.i / 3;
			from[perem.j][perem.k].z = map[perem.j][perem.k];
			perem.k++;
		}
		perem.j++;
	}
	from[perem.j] = NULL;
	return (from);
}

void	mlx_img_clear(t_fdf *fdf)
{
	char	*pixel;
	int		p;

	pixel = mlx_get_data_addr(fdf->img, &p, &p, &p);
	ft_bzero(pixel, WIDTH * HEIGHT * 4);
}
