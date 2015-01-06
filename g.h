/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 17:34:40 by laime             #+#    #+#             */
/*   Updated: 2014/12/30 21:30:41 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_H
# define G_H

# include "libft/libft.h"

# define WIDTH 800
# define HEIGHT 600

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*idata;
	int			ibits;
	int			isizeline;
	int			iendian;
	float		zoom;
	int			xoff;
	int			yoff;
	double		jx;
	double		jy;
	int			f;
}				t_env;

t_point			*pt_new(int x, int y, int z);
t_point			pt_get(int x, int y, int z);
void			img_put_pixel(t_env *env, int x, int y, int color);
void			img_put_line(t_env *env, t_point *pt1, t_point *pt2, int color);
void			img_draw(t_env *env);
void			img_fill(t_env *env, int color);

#endif
