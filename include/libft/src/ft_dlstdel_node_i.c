/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstdel_node_i.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 12:56:59 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/12 13:39:28 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_dlstdel_node_i(t_dlist_i **lst, t_dlist_i *del_node)
{
	if (*lst == NULL || del_node == NULL)
		return ;
	if (*lst == del_node)
		*lst = del_node->next;
	if (del_node->next != NULL)
		del_node->next->prev = del_node->prev;
	if (del_node ->prev != NULL)
		del_node->prev->next = del_node->next;
	free(del_node);
	return ;
}
