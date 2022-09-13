/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   purge_commands.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 10:15:21 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/13 10:28:35 by buiterma      ########   odam.nl         */
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
		while (g_shell.cmds[i].args[j])
		{
			free(g_shell.cmds[i].args[j]);
			j++;
		}
		free(g_shell.cmds[i].args);
		i++;
	}
	free(g_shell.cmds);
	g_shell.cmds = NULL;
	g_shell.cmd_n = 0;
}
