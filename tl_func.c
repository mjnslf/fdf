#include "fdf.h"

int	color(int z)
{
	if (z > 0)
		return (0x00ff0000);
	else
		return (0x000000ff);
}

void	next_str(char **str, char c)
{
	char	*temp;
	int		i;

	i = gnl_strlen(*str);
	temp = ft_strnew(i);
	ft_strcpy(temp, *str);
	free(*str);
	*str = ft_strnew(i + 1);
	ft_strcpy(*str, temp);
	(*str)[i] = c;
	free(temp);
}

int	num_count(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j++;
		while (str[i] && str[i] != ' ')
			i++;
		while (str[i] && str[i] == ' ')
			i++;
	}
	return (j);
}

char	**read_file(int fd, int *num_wid)
{
	char	*s;
	char	*str;
	char	**map;

	while (get_next_line(fd, &s))
	{
		str = gnl_strjoin(str, s);
		free(s);
		next_str(&str, '\n');
	}
	map = ft_split(str, '\n');
	free(str);
	free(s);
	*num_wid = num_count(*map);
	return (map);
}

void	mlx_pix_put(t_fdf *fdf, int x, int y, int z)
{
	char	*pixel;
	int		point;

	if (x > 0 && y > 0 && x < fdf->width && y < fdf->height)
	{
		pixel = mlx_get_data_addr(fdf->img, &point, &point, &point);
		point = WIDTH * y * 4 + x * 4;
		pixel[point + 0] = (int)(((z >> 16) & 0xFF));
		pixel[point + 1] = (int)((z & 0xFF));
	}
}
