/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstadd_back_i.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 12:41:17 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/12 13:39:33 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_dlstadd_back_i(t_dlist_i **lst, t_dlist_i *new_item)
{
	t_dlist_i	*last;

	if (lst && new_item)
	{
		if (!*lst)
			*lst = new_item;
		else
		{
			last = ft_dlstlast_i(*lst);
			last->next = new_item;
			new_item->prev = last;
		}
	}
	return ;
}
