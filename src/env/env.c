/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/02 11:51:56 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/09/06 11:25:09 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/shell.h"

static bool	fill_env(t_env *env, char *var_string)
{
	size_t	len[2];

	len[0] = 0;
	while (var_string[len[0]] != '=')
		len[0]++;
	len[1] = 0;
	while (var_string[len[0] + len[1] + 1])
		len[1]++;
	env->key = ft_calloc(sizeof(char), len[0] + 1);
	env->value = ft_calloc(sizeof(char), len[1] + 1);
	if (!env->key || !env->value)
	{
		free(env->key);
		free(env->value);
		free(env);
		return (false);
	}
	ft_memcpy(env->key, var_string, len[0]);
	ft_memcpy(env->value, &var_string[len[0] + 1], len[1]);
	return (true);
}

bool	clear_list(t_env **head)
{
	t_env	*thead;
	t_env	*next;

	thead = *head;
	while (head)
	{
		next = thead->next;
		free(thead->key);
		free(thead->value);
		free(thead);
		thead = next;
	}
	*head = NULL;
	return (false);
}

t_env	*get_env(t_env *head, char *key)
{
	while (head)
	{
		if (ft_strlen(head->key) == ft_strlen(key) \
			&& ft_strncmp(head->key, key, ft_strlen(head->key)) == 0)
			return (head);
		head = head->next;
	}
	return (NULL);
}

bool	add_variable(t_env **head, char *var_string)
{
	t_env	*tmp;
	t_env	*new;

	new = ft_calloc(1, sizeof(t_env));
	if (!new)
		return (false);
	if (!fill_env(new, var_string))
		return (false);
	if (*head == NULL)
	{
		*head = new;
		return (true);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (true);
}

bool	remove_variable(t_env **head, char *key)
{
	t_env	*tmp;
	t_env	*env;

	env = get_env(*head, key);
	if (!env)
		return (true);
	if (*head == env)
	{
		*head = (*head)->next;
		free(env->key);
		free(env->value);
		free(env);
		return (true);
	}
	tmp = *head;
	while (tmp->next != env)
		tmp = tmp->next;
	tmp->next = tmp->next->next;
	free(env->key);
	free(env->value);
	free(env);
	return (true);
}
