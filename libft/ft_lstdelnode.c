/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 15:47:31 by laime             #+#    #+#             */
/*   Updated: 2014/11/28 16:06:48 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstdelnode(t_list **node)
{
	if ((*node)->next != NULL)
	{
		(*node)->content = (*node)->next->content;
		(*node)->content_size = (*node)->next->content_size;
		(*node)->next = (*node)->next->next;
	}
	else
		*node = NULL;
}
