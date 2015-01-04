/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 13:57:23 by laime             #+#    #+#             */
/*   Updated: 2014/11/29 15:36:44 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

t_list		*ft_lstreverse(t_list *lst)
{
	t_list	*new;
	t_list	*next;

	while (lst != NULL)
	{
		next = lst->next;
		lst->next = new;
		new = lst;
		lst = next;
	}
	return (new);
}
