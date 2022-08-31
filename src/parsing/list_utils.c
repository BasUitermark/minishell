/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 11:20:58 by buiterma      #+#    #+#                 */
/*   Updated: 2022/08/31 11:58:11 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

t_token	*token_lstnew(unsigned index, unsigned length, t_token_type type)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (new == NULL)
		return (0);
	new->index = index;
	new->length = length;
	new->type = type;
	new->next = NULL;
	return (new);
}

void	token_lstadd_back(t_token **lst, t_token *new_item)
{
	t_token	*last;

	if (lst && new_item)
	{
		if (!*lst)
		{
			*lst = new_item;
			return ;
		}
		else
		{
			last = token_lstlast(*lst);
			last->next = new_item;
		}
	}
}

t_token	*token_lstlast(t_token *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
