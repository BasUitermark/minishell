/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_exit.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 09:53:34 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/17 11:44:25 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	exit_status(int exit_code)
{
	cleanup(NULL, exit_code % 256, true);
	if (g_shell.exit_code > 0)
		exit(g_shell.exit_code);
	exit(exit_code % 256);
}

static bool	strisnum(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[0] != '-')
			return (false);
		i++;
	}
	return (true);
}

int	cmd_exit(int argc, const char **argv)
{
	if (argc > 1 && (!strisnum(argv[1])))
	{
		if (g_shell.cmd_n == 1)
			ft_putendl_fd("exit", STDOUT_FILENO);
		exit(error("minishell", "exit", \
			"numeric argument required", 255));
	}
	if (argc > 2)
	{
		if (g_shell.cmd_n == 1)
			ft_putendl_fd("exit", STDOUT_FILENO);
		return (error("minishell", "exit", "too many arguments", 1));
	}
	if (g_shell.cmd_n == 1)
		ft_putendl_fd("exit", STDOUT_FILENO);
	if (!argv[1])
		exit_status(0);
	else
		exit_status(ft_atoi(argv[1]));
	return (1);
}
