/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_cd.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 13:34:33 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/19 11:08:13 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	free_home(t_env *home)
{
	free (home->key);
	free (home->value);
	free (home);
	home = NULL;
	return (1);
}

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
	if (chdir(path) < 0)
	{
		ft_putstr_fd((char *)path, STDERR_FILENO);
		ft_putendl_fd(": No such file or directory.", STDERR_FILENO);
		return (FALSE);
	}
	if (!set_pwd(cur_dir))
		return (FALSE);
	return (TRUE);
}

int	cmd_cd(int argc, const char **argv)
{
	t_env	*home;

	if (argc > 2)
	{
		ft_putendl_fd("Too many arguments.", STDERR_FILENO);
		return (1);
	}
	if (argc == 1 || (ft_strncmp(argv[1], "~", 1) == 0 && \
		ft_strlen(argv[1]) == 1))
	{
		home = get_env(g_shell.env, "HOME");
		if (!set_dir(home->value))
			return (free_home(home));
	}
	else if (ft_strncmp(argv[1], "-n", 1) == 0)
		ft_putendl_fd("CDEEZ NUTZ! :O", STDERR_FILENO);
	else
	{
		if (!set_dir(argv[1]))
			return (1);
	}
	return (0);
}
