/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:35:28 by laime             #+#    #+#             */
/*   Updated: 2014/11/23 13:57:33 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(const char *s)
{
	size_t	i;
	size_t	k;
	char	*temp;

	i = 0;
	if (!s)
		return (NULL);
	if ((k = ft_strlen(s) - 1) == 0)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	if (!*s || k == i - 1)
		return (ft_strnew(1));
	while (k > 0 && (s[k] == ' ' || s[k] == '\t' || s[k] == '\n'))
		k--;
	temp = ft_strsub(s, (unsigned int)i, (k - i + 1));
	return (temp);
}
