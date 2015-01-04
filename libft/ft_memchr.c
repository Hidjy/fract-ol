/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:23:17 by laime             #+#    #+#             */
/*   Updated: 2014/11/12 14:07:39 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*p;
	unsigned char	ca;

	i = 0;
	p = (unsigned char *)s;
	ca = (unsigned char)c;
	if (s == NULL)
		return (NULL);
	while (p && i < (int)n && p[i] != ca)
		i++;
	if ((int)n == i)
		return (NULL);
	return (void *)(s + i);
}
