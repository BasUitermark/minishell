/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   purge_commands.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 10:15:21 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/16 13:56:40 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	purge_commands(void)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < g_shell.cmd_n)
	{
		j = 0;
		if (g_shell.cmds[i].fd_in > 2)
			close(g_shell.cmds[i].fd_in);
		if (g_shell.cmds[i].fd_out > 2)
			close(g_shell.cmds[i].fd_out);
		while (g_shell.cmds[i].args[j])
		{
			free(g_shell.cmds[i].args[j]);
			j++;
		}
		free(g_shell.cmds[i].args);
		free(g_shell.cmds[i].path);
		i++;
	}
	free(g_shell.cmds);
	g_shell.cmds = NULL;
	g_shell.cmd_n = 0;
}
