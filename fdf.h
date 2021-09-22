#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
//#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> //for memory
#include <string.h>
//#include <assert.h>
#include <fcntl.h> //read

typedef struct
{
    int width;
    int height;
    int **z_matrix;
    int zoom;
    int color;
    int shift_x;
    int shift_y;
    
    void    *mlx_ptr;
    void    *win_ptr;
}               data;

void    read_file(char *file_name, data *data);
char**  ft_split(char const *str, char separator);
int     get_height(char *file_name);
int     ft_wdcount(char const *s, char c);
int     get_width(char *file_name);
void    fill_matrix(int *z_line, char *line);
void    read_file(char *file_name, data *data);
int     keyboard(int key, data *data);
int     get_next_line(int fd, char **line);
void    draw_line(float x, float y, float x1, float y1, data *data);
void    draw(data *data);
void    vec3d(float *x, float *y, int z);
int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);
int	rotate(float *x, float *y, int z);

#endif
