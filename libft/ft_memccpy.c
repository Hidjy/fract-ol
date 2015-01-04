/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:23:04 by laime             #+#    #+#             */
/*   Updated: 2014/11/17 15:35:01 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	int		i;
	char	*p1;
	char	*p2;

	i = 0;
	p1 = dst;
	p2 = src;
	if (dst == NULL || src == NULL)
		return (NULL);
	while ((size_t)i < n)
	{
		p1[i] = p2[i];
		if (p2[i] == c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
