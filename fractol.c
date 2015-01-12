/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 17:53:04 by laime             #+#    #+#             */
/*   Updated: 2015/01/04 17:53:06 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <X11/Xlib.h>
#include "libft/libft.h"
#include "fractol.h"
#include "g.h"

int		main(int ac, char **av)
{
	t_env	env;

	parse_args(&env, ac, av);
	env.mlx = mlx_init();
	if (env.mlx == NULL)
		return (-1);
	env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, "Fract'ol");
	env.img = mlx_new_image(env.mlx, WIDTH, HEIGHT);
	env.idata = mlx_get_data_addr(env.img, &(env.ibits),
				&(env.isizeline), &(env.iendian));
	mlx_expose_hook(env.win, draw, &env);
	mlx_key_hook(env.win, key, &env);
	mlx_mouse_hook(env.win, mouse, &env);
	if (env.f == 'j')
		mlx_hook(env.win, MotionNotify, PointerMotionMask, mousemove, &env);
	mlx_loop(env.mlx);
	return (0);
}

void	stop(char *str)
{
	ft_putendl(str);
	exit(3);
}

void	parse_args(t_env *env, int ac, char **av)
{
	(void)av;
	(void)env;
	if (ac != 2 || (av[1][0] != 'm' && av[1][0] != 'j' && av[1][0] != 'd' && av[1][0] != 's'))
		stop("Usage : ./fractol <fractal: m, j, d or s>");
	env->f = av[1][0];
	env->xoff = 0;
	env->yoff = 0;
	env->zoom = 1;
	if (env->f == 's')
		env->zoom = 1.0 / 81.0;
	env->p = 0;
}
