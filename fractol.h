/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 17:53:11 by laime             #+#    #+#             */
/*   Updated: 2015/01/04 17:53:13 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

# include "g.h"

void    stop(char *str);
void    parse_args(int ac, char **av);
int     draw(t_env *env);
int		mouse(int button, int x, int y, t_env *env);
int     mousemove(int x, int y, t_env *env);
int		key(int key, t_env *env);

#endif
