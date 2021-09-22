/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgregoro <mgregoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 12:43:31 by mgregoro          #+#    #+#             */
/*   Updated: 2021/09/21 19:19:42 by mgregoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

#define MAX(a, b) (a > b ? a : b)

float MOD(float i)
{
    return(i < 0) ? -i : i;
}

void    vec3d(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
}

void    draw_line(float x, float y, float x1, float y1, data *fdf)
{
    float x_step;
    float y_step;
    int max;
    int z;
    int z1;

    z = fdf->z_matrix[(int)y][(int)x];
    z1 = fdf->z_matrix[(int)y][(int)x];
    
    x *= fdf->zoom;
    y *= fdf->zoom;
    x1 *= fdf->zoom;
    y1 *= fdf->zoom;
    
    fdf->color = (z || z1) ? 0x00ffff : 0x804000;
    
    vec3d(&x, &y, z);
    vec3d(&x1, &y1, z1);
    
    //rotate(&x, &y, z);
    
    x += fdf->shift_x;
    y += fdf->shift_y;
    x1 += fdf->shift_x;
    y1 += fdf->shift_y;

    x_step = x1 - x;
    y_step = y1 - y;
    max = MAX(MOD(x_step), MOD(y_step));
    x_step /= max;
    y_step /= max;
    while((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, fdf->color);
        x += x_step;
        y += y_step;
    }
}

void draw(data *FDF)
{
    int x;
    int y;

    y = 0;
    while (y < FDF->height)
    {
        x = 0;
        while (x < FDF->width)
        {
            if (x < FDF->width)
                draw_line(x, y, x + 1, y, FDF);
            if(y < FDF->height - 1)
                draw_line(x, y, x, y + 1, FDF);
            x++;
        }
        y++;
    }
}