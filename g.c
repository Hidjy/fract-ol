/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 17:37:01 by laime             #+#    #+#             */
/*   Updated: 2014/12/31 16:30:44 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "g.h"
#include "libft/libft.h"

int			color(int n, int max, int p)
{
	double	i;
	int		r;
	int		g;
	int		b;

	i = (double)n / max;
	r = (sin(i * M_PI * 2 - M_PI_2) + 1) / 2 * 255;
	g = (sin(i * M_PI * 4 - M_PI_2) + 1) / 2 * 255;
	b = (sin(i * M_PI * 8 - M_PI_2) + 1) / 2 * 255;
	if (p == 0)
		return (0x10000 * r + 0x100 * g + b);
	else if (p == 1)
		return (0x10000 * r + 0x100 * b + g);
	else if (p == 2)
		return (0x10000 * b + 0x100 * r + g);
	else if (p == 3)
		return (0x10000 * b + 0x100 * g + r);
	else if (p == 4)
		return (0x10000 * g + 0x100 * r + b);
	return (0x10000 * g + 0x100 * b + r);
}

void		img_put_pixel(t_env *env, int x, int y, int color)
{
	char			*data;
	unsigned int	value;

	data = env->idata;
	value = mlx_get_color_value(env->mlx, color);
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		ft_memcpy(data + y * env->isizeline + x * (env->ibits / 8), &value, 3);
}

static void	img_put_hline(t_env *env, t_point *pt1, t_point *pt2, int color)
{
	int		i;

	i = pt1->x;
	while (i < pt2->x)
	{
		img_put_pixel(env, i, pt1->y + ((pt2->y - pt1->y) * \
					(i - pt1->x)) / (pt2->x - pt1->x), color);
		i++;
	}
}

static void	img_put_vline(t_env *env, t_point *pt1, t_point *pt2, int color)
{
	int		i;

	i = pt1->y;
	while (i < pt2->y)
	{
		img_put_pixel(env, pt1->x + ((pt2->x - pt1->x) * \
					(i - pt1->y)) / (pt2->y - pt1->y), i, color);
		i++;
	}
}

void		img_put_line(t_env *env, t_point *pt1, t_point *pt2, int color)
{
	if (fabs(pt1->x - pt2->x) > fabs(pt1->y - pt2->y))
	{
		if (pt1->x < pt2->x)
			img_put_hline(env, pt1, pt2, color);
		else
			img_put_hline(env, pt2, pt1, color);
	}
	else
	{
		if (pt1->y < pt2->y)
			img_put_vline(env, pt1, pt2, color);
		else
			img_put_vline(env, pt2, pt1, color);
	}
}
