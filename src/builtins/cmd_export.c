/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_export.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 16:39:37 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/19 11:07:58 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	*find_key(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		i++;
	}
	return (ft_substr(str, 0, i));
}

static char	*find_value(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		i++;
	}
	return (ft_substr(str, i + 1, ft_strlen(str)));
}

static bool	parse_variables(t_env **env_list, const char **argv, int argc)
{
	size_t	i;

	i = 0;
	if (!argv)
		return (false);
	while (i < argc)
	{
		if (!add_variable(env_list, (char *)argv[i]))
			return (clear_list(env_list));
		i++;
	}
	return (true);
}

int	cmd_export(int argc, const char **argv)
{
	int		i;
	t_env	*env_list;

	i = 1;
	env_list = NULL;
	if (argc < 1)
		return (1);
	if (!parse_variables(&env_list, &argv[1], argc - 1))
		return (1);
	while (i < argc && env_list)
	{
		if (!set_env(env_list->key, env_list->value))
			return (1);
		env_list = env_list->next;
		i++;
	}
	return (0);
}
