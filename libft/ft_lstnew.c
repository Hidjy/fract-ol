/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 19:50:04 by laime             #+#    #+#             */
/*   Updated: 2014/11/24 16:42:48 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*out;
	void	*cont;

	out = (t_list *)malloc(sizeof(t_list));
	if (out == NULL)
		return (NULL);
	out->content_size = (content != NULL) ? content_size : 0;
	cont = ft_memalloc(out->content_size);
	cont = ft_memcpy(cont, content, out->content_size);
	out->content = cont;
	out->next = NULL;
	return (out);
}
