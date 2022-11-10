/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_utility.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 13:25:21 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/11/10 13:49:01 by buiterma      ########   odam.nl         */
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

bool	exec_func(size_t index)
{
	int		status;
	size_t	x;

	x = 0;
	set_sigs_exec();
	while (index < g_shell.cmd_n)
	{
		if (!exec_child(index))
			return (false);
		index++;
	}
	waitpid(g_shell.pid, &status, 0);
	g_shell.exit_code = WEXITSTATUS(status);
	while (wait(&status) != -1)
		(void)"hello c:";
	exit(cleanup(NULL, g_shell.exit_code, true));
	return (true);
}
