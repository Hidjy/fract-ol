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
        env->zoom *= ZOOM;
        env->xoff = env->xoff * ZOOM + ((WIDTH - (WIDTH / ZOOM)) / 2) * ZOOM
                    + (x - WIDTH / 2) * ZOOM;
        env->yoff = env->yoff * ZOOM + ((HEIGHT - (HEIGHT / ZOOM)) / 2) * ZOOM
                    + (y - HEIGHT / 2) * ZOOM;
    }
    else if (button == 3) // Default : 4
    {
        env->zoom /= ZOOM;
        env->xoff = env->xoff / ZOOM - ((WIDTH - (WIDTH / ZOOM)) / 2) / ZOOM
                    + (x - WIDTH / 2) * ZOOM;
        env->yoff = env->yoff / ZOOM - ((HEIGHT - (HEIGHT / ZOOM)) / 2) / ZOOM
                    + (y - HEIGHT / 2) * ZOOM;
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
    double  i;
    double  r;
    double  g;
    double  b;

    i = (double)n / (double)max;
    r = sin(i * M_PI_2) / 2;
    g = sin(i * M_PI);
    b = sin(1 - i * M_PI_2) / 2 + 0.5;

    return get_color(0xFF * r, 0xFF * g, 0xFF * b);
    //*/
    //return get_color(remap(n, 0, max / 2), remap(n, 0, max), remap(n, 0, max * 2));
}

void       mandelbrot(t_env *env, int itmax)
{
    int x;
    int y;
    t_complex z;
    t_complex c;
    int i;

    x = 0;
    while (x <= WIDTH)
    {
        y = 0;
        while (y <= HEIGHT)
        {
            i = 0;
            c.x = (((x + env->xoff) / env->zoom / WIDTH) * 4 - 2);
            c.y = (((y + env->yoff) / env->zoom / HEIGHT) * 4 - 2);
            z.x = 0.0;
            z.y = 0.0;
            while ((z.x * z.x + z.y * z.y) < 4 && i < itmax)
                z.x = z.x * z.x + c.x, // TODO : Fix complex calcul
                z.y = z.y * z.y + c.y, //
                i++;
            img_put_pixel(env, x, y, color(i, itmax));
            y += 1;
        }
        x += 1;
    }
}

int     is_sierpinski_pixel_filled(int x, int y)
{
    x = (x < 0) ? -x : x;
    y = (y < 0) ? -y : y;
    while(x > 0 || y > 0)
    {
        if(x % 3 == 1 && y % 3 == 1)
            return (0);
        x /= 3;
        y /= 3;
    }
    return (1);
}

void       sierpinski(t_env *env)
{
    int x;
    int y;

    x = 0 - env->xoff;
    while (x <= (WIDTH - env->xoff))
    {
        y = 0 - env->yoff;
        while (y <= (HEIGHT - env->yoff))
        {
            if (is_sierpinski_pixel_filled(x, y))
                img_put_pixel(env,
                 (x + env->xoff),
                 (y + env->yoff),
                 0xFFFFFF);
            y += 1;
        }
        x += 1;
    }
}

void	img_draw(t_env *env)
{
    mandelbrot(env, 42);
    //sierpinski(env);
    /*
    t_point pt1, pt2;
    pt1 = pt_get(400, 0, 0);
    pt2 = pt_get(400, 600, 0);
    img_put_line(env, &pt1, &pt2, 0x777777);
    pt1 = pt_get(0, 300, 0);
    pt2 = pt_get(800, 300, 0);
    img_put_line(env, &pt1, &pt2, 0x777777);
    //*/
}
