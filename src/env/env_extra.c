/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_extra.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 13:20:49 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/11/01 13:24:24 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/shell.h"

t_env	*get_env(t_env *head, char *key)
{
	while (head)
	{
		if (ft_strcmp(head->key, key) == 0)
			return (head);
		head = head->next;
	}
	return (NULL);
}

void	place_env(t_env **head, t_env *node)
{
	t_env	*tmp;

	if (get_env(g_shell.env, node->key))
		remove_variable(&g_shell.env, node->key);
	if (ft_strcmp((*head)->key, node->key) > 0)
	{
		node->next = (*head);
		*head = node;
		return ;
	}
	tmp = *head;
	while (tmp->next && ft_strcmp(tmp->next->key, node->key) < 0)
		tmp = tmp->next;
	node->next = tmp->next;
	tmp->next = node;
}
