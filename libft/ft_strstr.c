/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:44:57 by laime             #+#    #+#             */
/*   Updated: 2014/11/12 14:17:54 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;
	int	chk;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (i <= (int)(ft_strlen(s1) - ft_strlen(s2)))
	{
		j = 0;
		chk = 1;
		while (j < (int)ft_strlen(s2))
		{
			if (s1[i + j] != s2[j])
				chk = 0;
			j++;
		}
		if (chk)
			return (char *)(s1 + i);
		i++;
	}
	return (NULL);
}
