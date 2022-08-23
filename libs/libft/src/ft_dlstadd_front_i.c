/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstadd_front_i.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 12:55:27 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/12 13:39:31 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_dlstadd_front_i(t_dlist_i **lst, t_dlist_i *new_item)
{
	new_item->next = *lst;
	if ((*lst) != NULL)
		(*lst)->prev = new_item;
	*lst = new_item;
}
