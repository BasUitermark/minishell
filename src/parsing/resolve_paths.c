/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   resolve_paths.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 12:46:38 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/11/17 13:02:01 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static bool	is_built_in(char *command)
{
	if (ft_strcmp(command, "echo") == 0 || \
		ft_strcmp(command, "cd") == 0 || \
		ft_strcmp(command, "pwd") == 0 || \
		ft_strcmp(command, "export") == 0 || \
		ft_strcmp(command, "unset") == 0 || \
		ft_strcmp(command, "env") == 0 || \
		ft_strcmp(command, "exit") == 0)
		return (true);
	return (false);
}

static char	*resolve_binary(char *command)
{
	int		index;
	char	**paths;
	char	*temp;
	char	*path;

	index = 0;
	if (ft_strchr("./", command[0]) && access(command, F_OK & X_OK) != -1)
		return (ft_strdup(command));
	if (!get_env(g_shell.env, "PATH"))
		return (NULL);
	paths = ft_split(get_env(g_shell.env, "PATH")->value, ':');
	path = NULL;
	while (paths && paths[index])
	{
		temp = ft_strjoin(paths[index], "/");
		path = ft_strjoin(temp, command);
		free(temp);
		if (access(path, F_OK & X_OK) != -1)
			break ;
		free(path);
		path = NULL;
		index++;
	}
	ft_freearray(paths);
	return (path);
}

bool	resolve_paths(void)
{
	size_t	index;

	index = 0;
	while (index < g_shell.cmd_n)
	{
		if (g_shell.cmds[index].args && \
			!is_built_in(g_shell.cmds[index].args[0]) && \
			g_shell.cmds[index].args[0][0])
		{
			g_shell.cmds[index].path = \
				resolve_binary(g_shell.cmds[index].args[0]);
			if (!g_shell.cmds[index].path)
				g_shell.cmds[index].invalid = true;
		}
		index++;
	}
	return (true);
}
