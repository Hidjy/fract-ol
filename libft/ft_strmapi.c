/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:30:32 by laime             #+#    #+#             */
/*   Updated: 2014/11/07 16:03:16 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	int		size;
	char	*out;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	size = (int)ft_strlen(s);
	out = (char *)malloc(sizeof(char) * size + 1);
	while (s[i])
	{
		out[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	out[i] = 0;
	return (out);
}
