/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 14:53:22 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/10/17 16:57:44 by jde-groo      ########   odam.nl         */
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
		return (ft_cd());
	if (ft_strncmp("exit", g_shell.cmds[index].args[0], 5) == 0)
		return (ft_exit());
	if (ft_strncmp("echo", g_shell.cmds[index].args[0], 5) == 0)
		return (ft_echo());
	if (ft_strncmp("env", g_shell.cmds[index].args[0], 4) == 0)
		return (ft_env());
	if (ft_strncmp("pwd", g_shell.cmds[index].args[0], 4) == 0)
		return (ft_env());
	if (ft_strncmp("export", g_shell.cmds[index].args[0], 7) == 0)
		return (ft_export());
	if (ft_strncmp("unset", g_shell.cmds[index].args[0], 6) == 0)
		return (ft_unset());
	return (127);
}

static void	ft_exec(int index)
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
	execve(g_shell.cmds[index].path, g_shell.cmds[index].args, normalize_env());
	ft_putstr_fd("command not found: ", STDERR_FILENO);
	ft_putstr_fd(g_shell.cmds[index].args[0], STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(127);
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

bool	exec_func(int index)
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
	//g_shell.exit_code = -999;

	//if (ft_strncmp("cd", g_shell.cmds[0].args[0], 3) == 0)
	//	g_shell.exit_code = ft_cd();
	//if (ft_strncmp("exit", g_shell.cmds[0].args[0], 5) == 0)
	//	g_shell.exit_code = ft_exit();
	//if (ft_strncmp("export", g_shell.cmds[0].args[0], 7) == 0)
	//	g_shell.exit_code = ft_export();
	//if (ft_strncmp("unset", g_shell.cmds[0].args[0], 6) == 0)
	//	g_shell.exit_code = ft_unset();
	//return (g_shell.exit_code != -999);
	g_shell.exit_code = exec_builtin(0);

	return (true);
}

bool	exec(void)
{
	if (g_shell.cmd_n == 1 && g_shell.cmds[0].path == NULL && \
		!g_shell.cmds[0].invalid && single_builtin())
		return (true);
	if (!ft_fork(&g_shell.pid))
		return (false);
	if (g_shell.pid == 0 && !exec_func(0))
		return (false);
	g_shell.pid = waitpid(0, &g_shell.exit_code, 0);
	return (true);
}
