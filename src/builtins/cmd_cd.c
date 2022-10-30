/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_cd.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 13:34:33 by buiterma      #+#    #+#                 */
/*   Updated: 2022/10/29 22:49:14 by buiterma      ########   odam.nl         */
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

	if (!path || chdir(path) < 0)
	{
		ft_putstr_fd((char *)path, STDERR_FILENO);
		ft_putendl_fd(": No such file or directory.", STDERR_FILENO);
		return (FALSE);
	}
	getcwd(cur_dir, PATH_MAX);
	if (!set_pwd(cur_dir))
		return (FALSE);
	return (TRUE);
}

static int	flags(int argc, const char *path)
{
	t_env	*user;

	if (ft_strncmp(path, "~", 1) == 0 && ft_strlen(path) == 1)
	{
		user = get_env(g_shell.env, "HOME");
		if (!user)
		{
			ft_putendl_fd("bash: cd: HOME not set", 2);
			cleanup(NULL);
			return (1);
		}
		if (set_dir(user->value))
			return (0);
	}
	else if (ft_strncmp(path, "-", 1) == 0 && ft_strlen(path) == 1)
	{
		user = get_env(g_shell.env, "OLDPWD");
		if (!user)
		{
			cleanup(NULL);
			return (1);
		}
		if (set_dir(user->value))
			return (0);
	}
	return (0);
}

int	cmd_cd(int argc, const char **argv)
{
	char	cur_dir[PATH_MAX];
	if (argc > 2)
	{
		ft_putendl_fd("bash: cd : too many arguments", STDERR_FILENO);
		g_shell.exit_code = 1;
		return (1);
	}
	if (ft_strlen(argv[1]) == 1)
		return (flags(argc, argv[1]));
	else if (ft_strncmp(argv[1], "-nuts", 5) == 0)
		ft_putstr_fd("CDEEZ NUTZ! :O\n", 1);
	else if (!set_dir(argv[1]))
		return (1);
	return (0);
}
