/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 14:05:11 by laime             #+#    #+#             */
/*   Updated: 2014/11/28 15:22:40 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstswap(t_list **elem1, t_list **elem2)
{
	void	*cont;
	size_t	size;

	if (!(elem1 && elem2 && *elem1 && *elem2))
		return ;
	cont = (*elem1)->content;
	size = (*elem1)->content_size;
	(*elem1)->content = (*elem2)->content;
	(*elem1)->content_size = (*elem2)->content_size;
	(*elem2)->content = cont;
	(*elem2)->content_size = size;
}
