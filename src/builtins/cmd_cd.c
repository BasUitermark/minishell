/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_cd.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 13:34:33 by buiterma      #+#    #+#                 */
/*   Updated: 2022/10/26 18:56:45 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static bool	set_pwd(char *old_dir)
{
	char	cur_dir[PATH_MAX];

	getcwd(cur_dir, PATH_MAX);
	if (!set_env("PWD", ft_strdup(cur_dir)))
		return (FALSE);
	if (!set_env("OLDPWD", ft_strdup(old_dir)))
		return (FALSE);
	return (TRUE);
}

static bool	set_dir(const char *path)
{
	char	cur_dir[PATH_MAX];

	getcwd(cur_dir, PATH_MAX);
	if (!path || chdir(path) < 0)
	{
		ft_putstr_fd((char *)path, STDERR_FILENO);
		ft_putendl_fd(": No such file or directory.", STDERR_FILENO);
		return (FALSE);
	}
	if (!set_pwd(cur_dir))
		return (FALSE);
	return (TRUE);
}

static int	tilde_flags(int argc, const char *path)
{
	t_env	*user;
	char	*hdir;

	if (argc == 1 || (ft_strncmp(path, "~", 1) == 0 && \
		ft_strlen(path) == 1))
	{
		user = get_env(g_shell.env, "USER");
		if (!user)
			return (0);
		hdir = ft_strjoin("/Users/", user->value);
		if (set_dir(hdir))
		{
			free(hdir);
			return (1);
		}
		free(hdir);
		return (0);
	}
	else if (ft_strncmp(path, "-nuts", 5) == 0)
		ft_putstr_fd("CDEEZ NUTZ! :O\n", 1);
	return (1);
}

int	cmd_cd(int argc, const char **argv)
{
	if (argc > 2)
	{
		ft_putendl_fd("Too many arguments.", STDERR_FILENO);
		return (0);
	}
	if (argc == 1 || (ft_strncmp(argv[1], "~", 1) == 0 && \
		ft_strlen(argv[1]) == 1))
	{
		tilde_flags(argc, argv[1]);
		return (0);
	}
	else if (!set_dir(argv[1]))
		return (0);
	return (0);
}
