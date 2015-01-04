/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:14:31 by laime             #+#    #+#             */
/*   Updated: 2014/11/12 14:39:21 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	ls1;
	size_t	ls2;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	if (ls1 > size)
		return (ls2 + size);
	while (s2[i] != '\0' && ls1 + i < size - 1)
	{
		s1[ls1 + i] = s2[i];
		i++;
	}
	s1[ls1 + i] = '\0';
	return (ls1 + ls2);
}
