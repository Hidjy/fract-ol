/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 16:42:30 by laime             #+#    #+#             */
/*   Updated: 2015/01/11 16:42:32 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "g.h"

int		color(int n, int max, int p)
{
	double	i;
	int		r;
	int		g;
	int		b;

	i = (double)n / max;
	r = (sin(i * M_PI * 2 - M_PI_2) + 1) / 2 * 255;
	g = (sin(i * M_PI * 4 - M_PI_2) + 1) / 2 * 255;
	b = (sin(i * M_PI * 8 - M_PI_2) + 1) / 2 * 255;
	if (p == 1)
		i = r,
		r = g,
		g = i;
	else if (p == 2)
		i = g,
		g = b,
		b = i;
	else if (p == 3)
		i = r,
		r = b,
		b = i;
	return (0x10000 * r + 0x100 * g + b);
}

int		mandelbrot(t_env *env, int x, int y, int itmax)
{
	int			i;
	t_complex	z;
	t_complex	c;
	t_complex	tmp;

	i = 0;
	c.x = (((x + env->xoff) / env->zoom / WIDTH) * 4 - 2);
	c.y = (((y + env->yoff) / env->zoom / HEIGHT) * 4 - 2);
	z.x = 0.0;
	z.y = 0.0;
	while ((z.x * z.x + z.y * z.y) < 4 && i < itmax)
	{
		tmp = z;
		z.x = tmp.x * tmp.x - tmp.y * tmp.y + c.x;
		z.y = tmp.x * tmp.y + tmp.x * tmp.y + c.y;
		i++;
	}
	return (i);
}

int		julia(t_env *env, int x, int y, int itmax)
{
	int			i;
	t_complex	z;
	t_complex	c;
	t_complex	tmp;

	i = 0;
	z.x = (((x + env->xoff) / env->zoom / WIDTH) * 4 - 2);
	z.y = (((y + env->yoff) / env->zoom / HEIGHT) * 4 - 2);
	c.x = env->jx;
	c.y = env->jy;
	while ((z.x * z.x + z.y * z.y) < 4 && i < itmax)
	{
		tmp = z;
		z.x = tmp.x * tmp.x - tmp.y * tmp.y + c.x;
		z.y = tmp.x * tmp.y + tmp.x * tmp.y + c.y;
		i++;
	}
	return (i);
}

int		douady(t_env *env, int x, int y, int itmax)
{
	int			i;
	t_complex	z;
	t_complex	c;
	t_complex	tmp;

	i = 0;
	z.x = (((x + env->xoff) / env->zoom / WIDTH) * 4 - 2);
	z.y = (((y + env->yoff) / env->zoom / HEIGHT) * 4 - 2);
	c.x = -0.123;
	c.y = -0.745;
	while ((z.x * z.x + z.y * z.y) < 4 && i < itmax)
	{
		tmp = z;
		z.x = tmp.x * tmp.x - tmp.y * tmp.y + c.x;
		z.y = tmp.x * tmp.y + tmp.x * tmp.y + c.y;
		i++;
	}
	return (i);
}

void	fractal(t_env *env, int itmax)
{
	int x;
	int y;
	int i;

	x = 0;
	while (x <= WIDTH)
	{
		y = 0;
		while (y <= HEIGHT)
		{
			if (env->f == 'm')
				i = mandelbrot(env, x, y, itmax);
			else if (env->f == 'j')
				i = julia(env, x, y, itmax);
			else if (env->f == 'd')
				i = douady(env, x, y, itmax);
			img_put_pixel(env, x, y, color(i, itmax, env->p));
			y += 1;
		}
		x += 1;
	}
}
