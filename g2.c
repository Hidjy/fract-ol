/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 16:16:30 by laime             #+#    #+#             */
/*   Updated: 2014/12/31 16:30:53 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"
#include "g.h"
#include "libft/libft.h"

t_point	*pt_new(int x, int y, int z)
{
	t_point	*pt;

	pt = (t_point *)malloc(sizeof(t_point));
	pt->x = x;
	pt->y = y;
	pt->z = z;
	return (pt);
}

void	pt_set(t_point *pt, int x, int y, int z)
{
	pt->x = x;
	pt->y = y;
	pt->z = z;
}


t_point	pt_get(int x, int y, int z)
{
	t_point	pt;

	pt.x = x;
	pt.y = y;
	pt.z = z;
	return (pt);
}

void	img_fill(t_env *env, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			img_put_pixel(env, i, j, color);
			j++;
		}
		i++;
	}
}
