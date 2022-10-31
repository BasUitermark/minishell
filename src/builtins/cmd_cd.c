/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_cd.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 13:34:33 by buiterma      #+#    #+#                 */
/*   Updated: 2022/10/31 15:40:35 by buiterma      ########   odam.nl         */
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
		return (error((char *)path, "No such file or directory", NULL, 0));
	if (!set_pwd(cur_dir))
		return (FALSE);
	return (TRUE);
}

static int	flags(int argc, const char *path)
{
	t_env	*user;

	if ((ft_strncmp(path, "~", 1) == 0 && ft_strlen(path) == 1) || argc == 1)
	{
		user = get_env(g_shell.env, "HOME");
		if (!user)
			return (error("minishell", "cd", "HOME not set", 1));
		if (set_dir(user->value))
			return (0);
	}
	else if (ft_strncmp(path, "-", 1) == 0 && ft_strlen(path) == 1)
	{
		user = get_env(g_shell.env, "OLDPWD");
		if (!user)
			return (error("minishell", "cd", "OLDPWD not set", 1));
		if (set_dir(user->value))
			return (0);
	}
	return (1);
}

int	cmd_cd(int argc, const char **argv)
{
	t_env	*user;

	if (argc > 2)
		return (error("bash", "cd", "too many arguments", 1));
	if (ft_strlen(argv[1]) == 1)
		return (flags(argc, argv[1]));
	if (argc == 1)
	{
		user = get_env(g_shell.env, "HOME");
		if (!user)
			return (error("minishell", "cd", "HOME not set", 1));
		if (set_dir(user->value))
			return (0);
	}
	else if (ft_strncmp(argv[1], "-nuts", 5) == 0)
		ft_putstr_fd("CDEEZ NUTZ! :O\n", 1);
	else if (!set_dir(argv[1]))
		return (1);
	return (1);
}
