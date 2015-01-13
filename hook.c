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

int		draw(t_env *env)
{
	ft_bzero(env->idata, env->isizeline * HEIGHT);
	img_draw(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	if (!(DEBUG))
		return (0);
	mlx_string_put(env->mlx, env->win, 10, 10, 0x777777, ft_itoa(env->zoom));
	return (0);
}

int		mousemove(int x, int y, t_env *env)
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
	if (button == 4 && env->zoom < 50000)
	{
		env->zoom *= ZOOM;
		env->xoff = env->xoff * ZOOM + ((WIDTH - (WIDTH / ZOOM)) / 2) * ZOOM
					+ (x - WIDTH / 2) * ZOOM - (x - WIDTH / 2);
		env->yoff = env->yoff * ZOOM + ((HEIGHT - (HEIGHT / ZOOM)) / 2) * ZOOM
					+ (y - HEIGHT / 2) * ZOOM - (y - HEIGHT / 2);
	}
	else if (button == 5 && env->zoom < 50000)
	{
		env->zoom /= ZOOM;
		env->xoff = env->xoff / ZOOM - ((WIDTH - (WIDTH / ZOOM)) / 2) / ZOOM
					- (x - WIDTH / 2) * ZOOM + (x - WIDTH / 2);
		env->yoff = env->yoff / ZOOM - ((HEIGHT - (HEIGHT / ZOOM)) / 2) / ZOOM
					- (y - HEIGHT / 2) * ZOOM + (y - HEIGHT / 2);
	}
	draw(env);
	return (0);
}

int		key(int key, t_env *env)
{
	if (key == 65307)
		stop("User exit.");
	else if (key == 65362)
		env->yoff -= 50;
	else if (key == 65364)
		env->yoff += 50;
	else if (key == 65361)
		env->xoff -= 50;
	else if (key == 65363)
		env->xoff += 50;
	else if (key == 65365 && env->zoom < 50000)
		env->zoom *= 1.1,
		env->xoff = env->xoff * ZOOM + ((WIDTH - (WIDTH / ZOOM)) / 2) * ZOOM,
		env->yoff = env->yoff * ZOOM + ((HEIGHT - (HEIGHT / ZOOM)) / 2) * ZOOM;
	else if (key == 65366 && env->zoom < 50000)
		env->zoom /= 1.1,
		env->xoff = env->xoff / ZOOM - ((WIDTH - (WIDTH / ZOOM)) / 2) / ZOOM,
		env->yoff = env->yoff / ZOOM - ((HEIGHT - (HEIGHT / ZOOM)) / 2) / ZOOM;
	else if (key == 32)
		env->p = (env->p == 5) ? 0 : env->p + 1;
	draw(env);
	return (0);
}

void	img_draw(t_env *env)
{
	int		i;

	fractal(env, ITMAX);
	if (DEBUG)
	{
		i = WIDTH;
		while (i--)
			img_put_pixel(env, i, HEIGHT / 2, 0x777777);
		i = HEIGHT;
		while (i--)
			img_put_pixel(env, WIDTH / 2, i, 0x777777);
	}
}
