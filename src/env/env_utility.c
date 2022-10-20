/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_utility.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 15:12:06 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/10/18 16:46:13 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/shell.h"

static unsigned int	env_length(void)
{
	unsigned int	length;
	t_env			*env;

	length = 0;
	env = g_shell.env;
	while (env)
	{
		length++;
		env = env->next;
	}
	return (length);
}

static bool	add_envstr(char **str, t_env *env)
{
	str[0] = ft_strappendfree(str[0], env->key);
	if (!str[0])
		return (false);
	str[0] = ft_strappendfree(str[0], "=");
	if (!str[0])
		return (false);
	str[0] = ft_strappendfree(str[0], env->value);
	if (!str[0])
		return (false);
	return (true);
}

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
	node = ft_calloc(sizeof(t_env), 1);
	if (!node)
		return (false);
	node->key = ft_strdup(key);
	node->value = value;
	if (!node->key)
	{
		free(node);
		return (false);
	}
	return (add_env(node));
}

char	**normalize_env(void)
{
	char	**res;
	t_env	*env;
	int		index;

	res = ft_calloc(sizeof(char *), env_length() + 1);
	if (!res)
		return (NULL);
	env = g_shell.env;
	index = 0;
	while (env)
	{
		if (!add_envstr(&res[index], env))
		{
			ft_freearray(res);
			return (NULL);
		}
		env = env->next;
		index++;
	}
	return (res);
}
