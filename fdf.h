#ifndef FDF_H
# define FDF_H
# include "minilibx_macos/mlx.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# define  WIDTH 1460
# define  HEIGHT 1080

typedef struct s_point
{
	float				x;
	float				y;
	float				z;
	int					rx;
	int					ry;
	int					i;
	int					j;
	int					k;
}			t_point;

typedef struct s_fdf
{
	void				*mlx;
	void				*win;
	void				*img;
	int					z_scale;
	int					width;
	int					height;
	t_point				**points;
	int					x_rasp;
	int					y_rasp;
	int					zoom;
	int					map_w;
	int					deltaerr;
	int					step_x;
	int					step_y;
}						t_fdf;

char			*ft_strnew(size_t size);
char			**ft_split(char const *s, char c);
int				ft_atoi(const char *str);
size_t			gnl_strlen(const char *s);
t_fdf			*param_init(int **map, int m_w);
char			**read_file(int fd, int *i);
void			vec3d(t_fdf *env);
int				color(int z);
void			x3d(t_fdf *e, t_point *p);
void			y3d(t_fdf *e, t_point *p);
void			drawing(t_fdf *env);
void			mlx_img_clear(t_fdf *env);
void			draw_line(t_fdf *env, t_point p1, t_point p2);
void			next_str(char **str, char c);
int				**matrix(char **map);
int				num_count(char *str);
t_point			**wid_mlx_to_map(int **map, int m_width);
int				draw(t_fdf *fdf);
int				*ft_read(char	*str);
int				keyboard(int keycode, t_fdf *e);
int				get_next_line(int fd, char **line);
void			ft_bzero(void *s, size_t n);
char			*ft_strcpy(char *dst, const char *src);
void			mlx_pix_put(t_fdf *e, int x, int y, int clr);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);

#endif
