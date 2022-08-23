/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstadd_front.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 12:55:24 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/12 12:55:25 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new_item)
{
	new_item->next = *lst;
	if ((*lst) != NULL)
		(*lst)->prev = new_item;
	*lst = new_item;
}
