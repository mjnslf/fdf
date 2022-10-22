#include "fdf.h"
#include <math.h>

int     keyboard(int key, data *FDF)
{
    (void) FDF;
    write(1, &key, sizeof(key));
    if (key == '~')
        FDF->shift_y -= 50;
    if(key == '}')
        FDF->shift_y += 50;
    if(key == '{')
        FDF->shift_x -= 50;
    if(key == '|')
        FDF->shift_x += 50;
    mlx_clear_window(FDF->mlx_ptr, FDF->win_ptr);
    draw(FDF);
    if (key == 53) //esk
        mlx_destroy_window(FDF->mlx_ptr, FDF->win_ptr);
        exit (0);
    return (0);
}

// int	rotate(float *x, float *y, int z)
// {
// 	float	    v = 0.0;

// 	*x = cos(0.8) * (*x) + sin(0.8) * z;
// 	z = -sin(0.8) * (*x) + cos(0.8) * z;

// 	*y = cos(0.8) * (*y) - sin(0.8) * z;
// 	z = sin(0.8) * (*y) + cos(0.8) * z;
// 	return (v);
// }

int main(int argc, char **argv)
{
    (void) argc;
    data *FDF;

    FDF = (data*)malloc(sizeof(data));
    read_file(argv[1], FDF);

    FDF->mlx_ptr = mlx_init();
    FDF->win_ptr = mlx_new_window(FDF->mlx_ptr, 500, 500, "FDF");
    FDF->zoom = 30;
    draw(FDF);
    mlx_key_hook(FDF->win_ptr, keyboard, FDF);
    mlx_loop(FDF->mlx_ptr);
}
