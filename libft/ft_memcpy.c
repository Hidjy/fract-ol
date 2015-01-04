/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 09:56:53 by laime             #+#    #+#             */
/*   Updated: 2014/11/12 14:05:51 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	int		i;
	char	*p1;
	char	*p2;

	i = 0;
	p1 = dst;
	p2 = src;
	if (dst == NULL || src == NULL)
		return (NULL);
	while (i < (int)n)
	{
		p1[i] = p2[i];
		i++;
	}
	return (dst);
}
