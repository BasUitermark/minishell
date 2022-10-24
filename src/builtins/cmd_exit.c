/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_exit.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 09:53:34 by buiterma      #+#    #+#                 */
/*   Updated: 2022/10/24 18:04:34 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	exit_status(int exit_code)
{
	free_program_data();
	clear_list(&g_shell.env);
	g_shell.exit_code = exit_code;
	
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
	{
		ft_putendl_fd("minishell: exit: too many arguments", STDERR_FILENO);
		return (1);
	}
	if (argc == 2 && (!strisnum(argv[1])))
	{
		ft_putstr_fd(BLUE BOLD SHELL RESET, STDERR_FILENO);
		ft_putendl_fd(": exit: numeric argument required", STDERR_FILENO);
		return (1);
	}
	ft_putendl_fd("exit", STDERR_FILENO);
	if (!argv[1])
		exit_status(0);
	else
		exit_status(ft_atoi(argv[1]));
	return (0);
}
