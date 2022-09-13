/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 14:53:22 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/09/13 17:01:45 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	exec_builtin(t_command *command)
{
	return (EXIT_FAILURE);
}

static bool	exec_child(t_command *command)
{
	int	pp[2];

	if (pipe(pp) == -1)
		return (false);
	g_shell.pid = fork();
	if (g_shell.pid == -1)
		return (false);
	if (g_shell.pid == 0)
	{
		close(pp[READ]);
		dup2(pp[WRITE], STDOUT_FILENO);
		if (command->path)
			execve(command->path, command->args, normalize_env());
		else
			exit(exec_builtin(command));
	}
	else
	{
		close(pp[WRITE]);
		dup2(pp[READ], STDIN_FILENO);
		waitpid(0, &g_shell.exit_code, 0);
		g_shell.exit_code = WEXITSTATUS(g_shell.exit_code);
	}
	return (true);
}

bool	exec(void)
{
	int		index;
	char	lol[256];
	int		r;

	index = 0;
	if (g_shell.fd_in != -1)
		dup2(g_shell.fd_in, STDIN_FILENO);
	while (index < g_shell.cmd_n)
	{
		if (!exec_child(&g_shell.cmds[index]))
			return (false);
		index++;
	}
	r = read(STDIN_FILENO, lol, 256);
	while (r)
	{
		write(g_shell.fd_out, lol, r);
		r = read(STDIN_FILENO, lol, 256);
	}
	return (true);
}
