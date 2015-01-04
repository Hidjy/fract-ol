/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 17:37:23 by laime             #+#    #+#             */
/*   Updated: 2014/11/25 16:21:46 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;

	map = NULL;
	while (lst != NULL)
	{
		ft_lstaddlast(&map, (*f)(lst));
		lst = lst->next;
	}
	return (map);
}
