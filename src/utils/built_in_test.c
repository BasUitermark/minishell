/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   built_in_test.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/19 14:30:22 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/19 14:36:47 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	builtin_test(void)
{
	if (ft_strncmp(g_shell.cmds[0].args[0], "pwd", 3) == 0)
		cmd_pwd();
	else if (ft_strncmp(g_shell.cmds[0].args[0], "cd", 2) == 0)
		cmd_cd(ft_arraylen(g_shell.cmds[0].args), \
		(const char **)g_shell.cmds[0].args);
	else if (ft_strncmp(g_shell.cmds[0].args[0], "env", 3) == 0)
		cmd_env();
	else if (ft_strncmp(g_shell.cmds[0].args[0], "export", 6) == 0)
		cmd_export(ft_arraylen(g_shell.cmds[0].args), \
		(const char **)g_shell.cmds[0].args);
	else if (ft_strncmp(g_shell.cmds[0].args[0], "echo", 4) == 0)
		cmd_echo(ft_arraylen(g_shell.cmds[0].args), \
		(const char **)g_shell.cmds[0].args);
	else if (ft_strncmp(g_shell.cmds[0].args[0], "unset", 5) == 0)
		cmd_unset(ft_arraylen(g_shell.cmds[0].args), \
		(const char **)g_shell.cmds[0].args);
	else if (ft_strncmp(g_shell.cmds[0].args[0], "exit", 4) == 0)
		cmd_exit(ft_arraylen(g_shell.cmds[0].args), \
		(const char **)g_shell.cmds[0].args);
	else
	{
		ft_putstr_fd(RED BOLD"Error"RESET, STDERR_FILENO);
		ft_putendl_fd(": Command not found!", STDERR_FILENO);
	}
}
