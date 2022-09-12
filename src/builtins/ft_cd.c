/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cd.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 13:34:33 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/12 16:30:16 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "shell.h"
#include "../../include/shell.h"
#include "../../libs/libft/include/libft.h"
#include <stdio.h>

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
	char	*cur_dir;

	cur_dir = getcwd(NULL, -1);
	if (!cur_dir)
		return (FALSE);
	if (!set_env("PWD", old_dir))
	{
		free (cur_dir);
		return (FALSE);
	}
	if (!set_env("OLDPWD", cur_dir))
	{
		free (cur_dir);
		return (FALSE);
	}
	return (TRUE);
}

static bool	set_dir(const char *path)
{
	char	*cur_dir;

	cur_dir = getcwd(NULL, -1);
	if (chdir(path) < 0)
	{
		ft_putstr_fd((char *)path, STDERR_FILENO);
		ft_putendl_fd(": No such file or directory.", STDERR_FILENO);
		free(cur_dir);
		return (FALSE);
	}
	if (!set_pwd(cur_dir))
	{
		free(cur_dir);
		return (FALSE);
	}
	return (TRUE);
}

int	ft_cd(int argc, const char **argv)
{
	t_env	*home;

	if (argc > 2)
	{
		ft_putendl_fd("Too many arguments.", STDERR_FILENO);
		return (1);
	}
	if (argc == 1 || ft_strncmp(argv[1], "~", 1) == 0)
	{
		home = get_env(g_shell.env, "HOME");
		if (!set_dir(home->value))
			return (free_home(home));
	}
	if (ft_strncmp(argv[1], "-n", 1) == 0)
		ft_putendl_fd("CDEEZ NUTZ! :O", STDERR_FILENO);
	else
	{
		if (!set_dir(argv[1]))
			return (1);
	}
	return (0);
}

// int	main(int argc, char const *argv[], char **envp)
// {
// 	t_env	*pwd;
// 	t_env	*old_pwd;

// 	parse_environment(envp);
// 	pwd = get_env(g_shell.env, "PWD");
// 	old_pwd = get_env(g_shell.env, "OLDPWD");
// 	printf(BOLD GREEN"pwd:	%s\nold pwd:%s\n" RESET, pwd->value, old_pwd->value);
// 	ft_cd(argc - 1, &argv[1]);
// 	return (0);
// }
