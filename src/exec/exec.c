/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 14:53:22 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/10/31 16:38:03 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

bool	ft_pipe(int fds[2])
{
	if (pipe(fds) == -1)
		return (false);
	return (true);
}

bool	ft_fork(pid_t *pid)
{
	pid_t	output;

	output = fork();
	if (output == -1)
		return (false);
	*pid = output;
	return (true);
}

static int	exec_builtin(int index)
{
	if (ft_strncmp("cd", g_shell.cmds[index].args[0], 3) == 0)
		return (cmd_cd(ft_arraylen(g_shell.cmds[0].args), \
		(const char **)g_shell.cmds[index].args));
	if (ft_strncmp("exit", g_shell.cmds[index].args[0], 5) == 0)
		return (cmd_exit(ft_arraylen(g_shell.cmds[index].args), \
		(const char **)g_shell.cmds[index].args));
	if (ft_strncmp("echo", g_shell.cmds[index].args[0], 5) == 0)
		return (cmd_echo(ft_arraylen(g_shell.cmds[index].args), \
		(const char **)g_shell.cmds[index].args));
	if (ft_strncmp("env", g_shell.cmds[index].args[0], 4) == 0)
		return (cmd_env(ft_arraylen(g_shell.cmds[index].args), \
		(const char **)g_shell.cmds[index].args));
	if (ft_strncmp("pwd", g_shell.cmds[index].args[0], 4) == 0)
		return (cmd_pwd());
	if (ft_strncmp("export", g_shell.cmds[index].args[0], 7) == 0)
		return (cmd_export(ft_arraylen(g_shell.cmds[index].args), \
		(const char **)g_shell.cmds[index].args));
	if (ft_strncmp("unset", g_shell.cmds[index].args[0], 6) == 0)
		return (cmd_unset(ft_arraylen(g_shell.cmds[index].args), \
		(const char **)g_shell.cmds[index].args));
	return (127);
}

static void	ft_exec(size_t index)
{
	if (index == 0 && g_shell.fd_in != STDIN_FILENO)
	{
		dup2(g_shell.fd_in, STDIN_FILENO);
		close(g_shell.fd_in);
	}
	if (index == g_shell.cmd_n - 1 && g_shell.fd_out != STDOUT_FILENO)
	{
		dup2(g_shell.fd_out, STDOUT_FILENO);
		close(g_shell.fd_out);
	}
	if (g_shell.cmds[index].path == NULL && !g_shell.cmds[index].invalid)
		exit(exec_builtin(index));
	if (!access(g_shell.cmds[index].args[0], R_OK))
		exit(error("minishell", g_shell.cmds[index].args[0], \
			"Permission denied", 126));
	execve(g_shell.cmds[index].path, g_shell.cmds[index].args, normalize_env());
	exit(error("command not found", g_shell.cmds[index].args[0], NULL, 127));
}

bool	exec_child(int index)
{
	int		fd[2];

	if (!ft_pipe(fd))
		return (false);
	if (!ft_fork(&g_shell.pid))
	{
		close(fd[READ]);
		close(fd[WRITE]);
		return (false);
	}
	if (g_shell.pid == 0)
	{
		dup2(fd[WRITE], STDOUT_FILENO);
		close(fd[WRITE]);
		close(fd[READ]);
		ft_exec(index);
	}
	else
	{
		dup2(fd[READ], STDIN_FILENO);
		close(fd[READ]);
		close(fd[WRITE]);
	}
	return (true);
}

bool	exec_func(size_t index)
{
	while (index < g_shell.cmd_n - 1)
	{
		if (!exec_child(index))
			return (false);
		index++;
	}
	ft_exec(index);
	return (true);
}

static bool	single_builtin(void)
{
	g_shell.exit_code = exec_builtin(0);
	return (true);
}

bool	exec(void)
{
	set_sigs_exec();
	// g_shell.exit_code = 0;
	if (g_shell.cmd_n == 0)
		return (true);
	if (g_shell.cmd_n == 1 && g_shell.cmds[0].path == NULL && \
		!g_shell.cmds[0].invalid && single_builtin())
		return (true);
	if (!ft_fork(&g_shell.pid))
		return (false);
	if (g_shell.pid == 0 && !exec_func(0))
		return (false);
	g_shell.pid = waitpid(0, &g_shell.exit_code, 0);
	g_shell.exit_code = WEXITSTATUS(g_shell.exit_code);
	return (true);
}
