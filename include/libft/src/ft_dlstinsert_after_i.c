/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstinsert_after_i.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 12:59:26 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/12 13:39:27 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_dlstinsert_after_i(t_dlist_i *prev_node, t_dlist_i *new_item)
{
	if (prev_node == NULL)
		return ;
	new_item->next = prev_node->next;
	prev_node->next = new_item;
	new_item->prev = prev_node;
	if (new_item->next != NULL)
		new_item->next->prev = new_item;
}
