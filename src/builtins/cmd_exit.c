/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_exit.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 09:53:34 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/15 19:12:43 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
// #include "../../include/shell.h"
// #include "../../libs/libft/include/libft.h"
// #include <stdio.h>

static bool	strisnum(const char *str)
{
	size_t	i;

	i = 0;
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
	// if (!strisnum(argv[1]))
	// {
	// 	ft_putstr_fd(BLUE BOLD SHELL RESET, STDERR_FILENO);
	// 	ft_putendl_fd(": exit: numeric argument required", STDERR_FILENO);
	// 	return (1);
	// }
	ft_putendl_fd("exit", STDERR_FILENO);
	// free_program_data();
	// clear_list(&g_shell.env);
	if (!argv[1])
		exit(0);
	exit(ft_atoi(argv[1]));
}
