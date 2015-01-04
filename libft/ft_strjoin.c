/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:17:37 by laime             #+#    #+#             */
/*   Updated: 2014/11/23 12:56:41 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*temp;
	char	*ret;

	if (!s1 && s2)
		return (ft_strdup((char*)s2));
	else if (!s2 && s1)
		return (ft_strdup((char*)s1));
	else if (!s1 && !s2)
		return (NULL);
	temp = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!temp)
		return (NULL);
	ret = temp;
	temp = ft_strcpy(temp, s1);
	temp = ft_strcat(temp, (char *)s2);
	return (ret);
}
