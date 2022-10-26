/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_export.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 16:39:37 by buiterma      #+#    #+#                 */
/*   Updated: 2022/10/26 11:44:33 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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
			ft_putstr_fd(env->value, STDOUT_FILENO);
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
	if (!env->key)
	{
		free(env);
		return (false);
	}
	place_env(&g_shell.env, env);
	return (true);
}

static void	print_err(char *str)
{
	ft_putstr_fd("export: `", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
}

int	cmd_export(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 1)
		return (print_env());
	while (argv[i + 1])
	{
		i++;
		if (!is_valid_key(argv[i]))
		{
			print_err(argv[i]);
			continue ;
		}
		if (ft_strchr(argv[i], '=') == NULL)
		{
			if (!handle_no_val(argv[i]))
				return (EXIT_FAILURE);
			else
				continue ;
		}
		if (!add_variable(&g_shell.env, argv[i]))
			return (EXIT_FAILURE);
	}
	return (0);
}
