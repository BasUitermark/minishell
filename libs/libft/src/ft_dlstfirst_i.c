/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstfirst_i.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 12:58:31 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/12 13:39:26 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_dlist_i	*ft_dlstfirst_i(t_dlist_i *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev != NULL)
		lst = lst->prev;
	return (lst);
}
