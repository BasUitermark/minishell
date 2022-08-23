/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstfirst.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 12:58:10 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/12 12:58:11 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_dlist	*ft_dlstfirst(t_dlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev != NULL)
		lst = lst->prev;
	return (lst);
}
