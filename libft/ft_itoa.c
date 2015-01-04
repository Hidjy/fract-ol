/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:48:46 by laime             #+#    #+#             */
/*   Updated: 2014/11/11 15:10:59 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static char	*pouet(void)
{
	char	*out;

	out = ft_strnew(11);
	if (out == NULL)
		return (NULL);
	out[0] = '-';
	out[1] = '2';
	out[2] = '1';
	out[3] = '4';
	out[4] = '7';
	out[5] = '4';
	out[6] = '8';
	out[7] = '3';
	out[8] = '6';
	out[9] = '4';
	out[10] = '8';
	return (out);
}

char		*ft_itoa(int n)
{
	char	*out;
	int		i;
	size_t	len;

	i = 0;
	len = ft_intlen(n);
	if (n == -2147483648)
		return (pouet());
	out = ft_strnew(len);
	if (out == NULL)
		return (NULL);
	if (n < 0)
	{
		out[0] = '-';
		n = -n;
		i++;
	}
	while (i < (int)len)
	{
		out[i] = (n / ft_pow(10, len - i - 1)) % 10 + '0';
		i++;
	}
	return (out);
}
