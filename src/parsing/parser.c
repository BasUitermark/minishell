/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 11:29:47 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/15 13:57:46 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	parts(char *cmd)
{
	int	index;
	int	parts;

	index = 0;
	parts = 1;
	if (cmd[0] == '\'')
		return (parts);
	while (cmd[index])
	{
		if (cmd[index] == ' ')
			parts++;
		index++;
	}
	return (parts);
}

static void	free_two_things_because_norm(void *one, void *two)
{
	free(one);
	free(two);
}

static bool	redo_args(t_command *cmd)
{
	int		index[2];
	char	**split_newargs[2];

	split_newargs[0] = ft_split(cmd->args[0], ' ');
	if (!split_newargs[0])
		return (false);
	split_newargs[1] = ft_calloc(ft_arraylen(cmd->args) + \
		ft_arraylen(split_newargs[0]), sizeof(char *));
	if (!split_newargs[1])
		return (ft_freearray(split_newargs[0]) != NULL);
	ft_memset(index, 0, sizeof(int) * 2);
	while (split_newargs[0][index[0]])
	{
		split_newargs[1][index[0]] = split_newargs[0][index[0]];
		index[0]++;
	}
	free_two_things_because_norm(cmd->args[0], split_newargs[0]);
	while (cmd->args[1 + index[1]])
	{
		split_newargs[1][index[0] + index[1]] = cmd->args[1 + index[1]];
		index[1]++;
	}
	free(cmd->args);
	cmd->args = split_newargs[1];
	return (true);
}

static bool	parse_env_cmds(void)
{
	size_t	index;

	index = 0;
	while (index < g_shell.cmd_n)
	{
		if (parts(g_shell.cmds[index].args[0]) > 1)
			if (!redo_args(&g_shell.cmds[index]))
				return (false);
		index++;
	}
	return (true);
}

bool	parser(t_token **token, char const *input)
{
	if (!parse_commands(*token, input))
		return (false);
	if (!parse_special(*token, input))
		return (false);
	if (!parse_env_cmds())
		return (false);
	return (true);
}
