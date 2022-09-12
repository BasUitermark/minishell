/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utility.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 15:12:06 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/09/12 15:28:51 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/shell.h"

bool	add_env(t_env *node)
{
	t_env	*tmp;

	tmp = g_shell.env;
	if (g_shell.env == NULL)
	{
		g_shell.env = node;
		return (true);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (true);
}

bool	set_env(char *key, char *value)
{
	t_env	*node;

	node = get_env(g_shell.env, key);
	if (node)
	{
		free(node->value);
		node->value = value;
		return (true);
	}
	node == ft_calloc(sizeof(t_env), 1);
	if (!node)
		return (false);
	node->key = ft_strdup(key);
	node->value = value;
	if (node->key)
	{
		free(node);
		return (false);
	}
	return (add_env(node));
}
