/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_exit.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 09:53:34 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/10 13:26:58 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	exit_status(int exit_code)
{
	cleanup(NULL, exit_code, true);
	if (g_shell.exit_code > 0)
		exit(g_shell.exit_code);
	exit(exit_code);
}

static bool	strisnum(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int	cmd_exit(int argc, const char **argv)
{
	if (argc > 2)
		return (error("minishell", "exit", "too many arguments", 1));
	if (argc == 2 && (!strisnum(argv[1])))
		return (error(BLUE BOLD SHELL RESET, "exit", \
			"numeric argument required", 1));
	ft_putendl_fd("exit", STDOUT_FILENO);
	if (!argv[1])
		exit_status(0);
	else
		exit_status(ft_atoi(argv[1]));
	return (1);
}
