/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:54:59 by laime             #+#    #+#             */
/*   Updated: 2014/11/13 12:20:55 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sign(const char *str, int *i)
{
	if (str[*i] == '-' && ft_isdigit(str[*i + 1]))
	{
		*i = *i + 1;
		return (-1);
	}
	else if (str[*i] == '+')
		*i = *i + 1;
	return (1);
}

int			ft_atoi(const char *str)
{
	int	i;
	int	y;
	int	out;

	i = 0;
	y = 1;
	out = 0;
	if (str == NULL)
		return (0);
	while ((str[i] > 7 && str[i] <= 32 && str[i] != 27))
		i++;
	y = sign(str, &i);
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		out *= 10;
		out += str[i] - 48;
		i++;
	}
	return (out * y);
}
