/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:30:06 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/09 12:13:45 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	error(char *cmd, char *input, char *msg, int exit_code)
{
	if (cmd)
	{
		ft_putstr_fd(cmd, STDERR_FILENO);
		if (input)
			write(STDERR_FILENO, ": ", 2);
	}
	if (input)
	{
		ft_putstr_fd(input, STDERR_FILENO);
		if (msg)
			write(STDERR_FILENO, ": ", 2);
	}
	if (msg)
		ft_putstr_fd(msg, STDERR_FILENO);
	write(STDERR_FILENO, "\n", 1);
	return (exit_code);
}
