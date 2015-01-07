/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 19:38:21 by laime             #+#    #+#             */
/*   Updated: 2015/01/04 19:38:22 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <complex.h>
#include "g.h"
#include "fractol.h"

int     draw(t_env *env)
{
    ft_bzero(env->idata, env->isizeline * HEIGHT);
    img_draw(env);
    mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
    return (0);
}

int     mousemove(int x, int y, t_env *env)
{
    env->jx = ((double)x / (double)WIDTH) * 2.0 - 1.0;
    env->jy = ((double)y / (double)HEIGHT) * 2.0 - 1.0;
    if (x % 5 == 0 || y % 5 == 0)
        draw(env);
    return (0);
}

int		mouse(int button, int x, int y, t_env *env)
{
    (void)x;
    (void)y;
    if (button == 1) // Default : 5
    {
        env->xoff += WIDTH * 0.05 * env->zoom + (x - WIDTH / 2);
        env->yoff += HEIGHT * 0.05 * env->zoom + (y - HEIGHT / 2);
        env->zoom *= 1.1;
    }
    else if (button == 3) // Default : 4
    {
        env->zoom /= 1.1;
        env->xoff -= WIDTH * 0.05 * env->zoom + (x - WIDTH / 2);
        env->yoff -= HEIGHT * 0.05 * env->zoom + (y - HEIGHT / 2);
    }
    //ft_putendl(ft_itoa(button));
    draw(env);
    return (0);
}

int		key(int key, t_env *env)
{
    if (key == 65307)
        stop("User exit.");
    else if (key == 65362)
        env->yoff += 50;
    else if (key == 65364)
        env->yoff -= 50;
    else if (key == 65361)
        env->xoff += 50;
    else if (key == 65363)
        env->xoff -= 50;
    else
        ft_putendl(ft_itoa(key));
    draw(env);
    return (0);
}

int     get_color(int r, int g, int b)
{
    return (r * 0x10000 + g * 0x100 + b);
}

int     remap(int x, int in_min, int in_max)
{
    return ((x - in_min) * (255 - 0) / (in_max - in_min) + 0);
}

int     color(int n, int max)
{
    //*
    double  r;
    double  g;
    double  b;

    r = (double)n / (double)max;
    g = sin(r * M_PI_2);
    b = sin(g * M_PI_2);
    return get_color(0xFF * r, 0xFF * g, 0xFF * b);
    //*/
    //return get_color(remap(n, 0, max / 2), remap(n, 0, max), remap(n, 0, max * 2));
}

void       mandelbrot(t_env *env, int itmax)
{
    int x;
    int y;
    double complex Z;
    double complex C;
    int i;

    x = 0;
    while (x <= WIDTH)
    {
        y = 0;
        while (y <= HEIGHT)
        {
            i = 0;
            C = (((x + env->xoff) / env->zoom / WIDTH) * 4 - 2) +
             (((y + env->yoff) / env->zoom / HEIGHT) * 4 - 2) * I;
            Z = 0.0 + 0.0 * I;
            while (cabs(Z) < 2 && i < itmax)
                Z = Z * Z + C,
                i++;
            img_put_pixel(env, x, y, color(i, itmax));
            y += 1;
        }
        x += 1;
    }
}

void	img_draw(t_env *env)
{
     mandelbrot(env, 84);
    //*
    t_point pt1, pt2;
    pt1 = pt_get(400, 0, 0);
    pt2 = pt_get(400, 600, 0);
    img_put_line(env, &pt1, &pt2, 0x777777);
    pt1 = pt_get(0, 300, 0);
    pt2 = pt_get(800, 300, 0);
    img_put_line(env, &pt1, &pt2, 0x777777);
    //*/
}
