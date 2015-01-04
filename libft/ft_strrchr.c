/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:26:07 by laime             #+#    #+#             */
/*   Updated: 2014/11/12 14:16:07 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	if (s == NULL)
		return (NULL);
	while (i <= (int)ft_strlen(s))
	{
		if (s[i] == c)
			res = (char *)(s + i);
		i++;
	}
	return (res);
}
