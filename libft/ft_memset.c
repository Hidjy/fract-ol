/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:53:50 by laime             #+#    #+#             */
/*   Updated: 2014/11/12 14:04:41 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*p;

	i = 0;
	p = b;
	if (b == NULL)
		return (NULL);
	while (i < (int)len)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
