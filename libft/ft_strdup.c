/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:02:55 by laime             #+#    #+#             */
/*   Updated: 2014/11/20 13:50:31 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;

	if (s1 == NULL)
		return (NULL);
	s2 = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	s2 = ft_strcpy(s2, s1);
	if (s2)
		s2[ft_strlen(s1)] = '\0';
	return (s2);
}
