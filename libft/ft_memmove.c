/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 21:25:30 by laime             #+#    #+#             */
/*   Updated: 2014/11/10 13:00:23 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*p1;
	char	*p2;
	char	tmp[len];

	i = 0;
	p1 = (char *)dst;
	p2 = (char *)src;
	if (dst == NULL || src == NULL)
		return (NULL);
	while (i < (int)len)
	{
		tmp[i] = p2[i];
		i++;
	}
	i = 0;
	while (i < (int)len)
	{
		p1[i] = tmp[i];
		i++;
	}
	return (dst);
}
