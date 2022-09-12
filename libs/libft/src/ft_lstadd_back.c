/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/09 18:55:04 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/09 18:55:05 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_item)
{
	t_list	*last;

	if (lst && new_item)
	{
		if (!*lst)
		{
			*lst = new_item;
			return ;
		}
		else
		{
			last = ft_lstlast(*lst);
			last->next = new_item;
		}
	}
}
