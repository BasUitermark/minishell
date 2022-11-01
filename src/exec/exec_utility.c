/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_utility.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 13:25:21 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/11/01 13:27:01 by jde-groo      ########   odam.nl         */
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
	while (index < g_shell.cmd_n - 1)
	{
		if (!exec_child(index))
			return (false);
		index++;
	}
	ft_exec(index);
	return (true);
}
