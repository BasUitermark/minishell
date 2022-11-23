/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_export.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 16:39:37 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/23 13:19:52 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	print_val(char *val, int fd)
{
	int	i;

	i = 0;
	while (val[i])
	{
		if (val[i] == '"')
			ft_putchar_fd('\\', fd);
		ft_putchar_fd(val[i], fd);
		i++;
	}
}

static int	print_env(void)
{
	t_env	*env;

	env = g_shell.env;
	while (env)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(env->key, STDOUT_FILENO);
		if (env->value)
		{
			ft_putstr_fd("=\"", STDOUT_FILENO);
			print_val(env->value, STDOUT_FILENO);
			ft_putchar_fd('"', STDOUT_FILENO);
		}
		ft_putchar_fd('\n', STDOUT_FILENO);
		env = env->next;
	}
	return (EXIT_SUCCESS);
}

static bool	is_valid_key(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (false);
	if (!ft_isalpha(str[index]) && str[index] != '_')
		return (false);
	while (str[index] && str[index] != '=')
	{
		if (!ft_isalnum(str[index]) && str[index] != '_')
			return (false);
		index++;
	}
	return (true);
}

static bool	handle_no_val(char *str)
{
	t_env	*env;

	if (get_env(g_shell.env, str))
		return (true);
	env = ft_calloc(1, sizeof(t_env));
	if (!env)
		return (false);
	env->hidden = true;
	env->key = ft_strdup(str);
	env->value = NULL;
	if (!env->key)
	{
		free(env);
		return (false);
	}
	place_env(&g_shell.env, env);
	return (true);
}

int	cmd_export(int argc, const char **argv)
{
	int		i;

	i = 0;
	if (argc == 1)
		return (print_env());
	while (argv[i + 1])
	{
		i++;
		if (!is_valid_key((char *)argv[i]))
		{
			error("export", (char *) argv[i], "not a valid identifier", 1);
			continue ;
		}
		if (ft_strchr((char *)argv[i], '=') == NULL)
		{
			if (!handle_no_val((char *)argv[i]))
				return (EXIT_FAILURE);
			else
				continue ;
		}
		if (!add_variable(&g_shell.env, (char *)argv[i]))
			return (EXIT_FAILURE);
	}
	return (0);
}
