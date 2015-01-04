/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:13:29 by laime             #+#    #+#             */
/*   Updated: 2014/11/20 16:25:57 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	int	i;

	i = 0;
	if (dst == NULL || src == NULL)
		return (NULL);
	while (src[i] && (size_t)i < n)
	{
		dst[i] = src[i];
		i++;
	}
	while ((size_t)i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
