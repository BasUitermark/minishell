/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dlstnew_i.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 12:36:40 by buiterma      #+#    #+#                 */
/*   Updated: 2022/07/12 13:39:20 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_dlist_i	*ft_dlstnew_i(int input)
{
	t_dlist_i	*head;

	head = (t_dlist_i *)malloc(sizeof(t_dlist_i));
	if (head == NULL)
		return (0);
	head->num = input;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}
