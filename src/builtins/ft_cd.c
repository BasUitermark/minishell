/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cd.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 13:34:33 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/12 15:05:00 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "shell.h"
#include "../../include/shell.h"
#include "../../libs/libft/include/libft.h"
#include <stdio.h>

static bool	set_pwd(char *old_dir)
{
	cur_dir = getcwd(NULL, -1);
	g_shell.env = get_env(g_shell.env, "OLDPWD");
	free (g_shell.env->value);
	g_shell.env->value = old_dir;
	g_shell.env = get_env(g_shell.env, "PWD");
	free (g_shell.env->value);
	g_shell.env->value = cur_dir;
	free(cur_dir);
}

static bool	set_dir(const char *path)
{
	char	*cur_dir;

	cur_dir = getcwd(NULL, -1);
	if (chdir(path) < 0)
	{
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putendl_fd(": No such file or directory.", STDERR_FILENO);
		free(cur_dir);
		return (FALSE);
	}
	if (!set_pwd(cur_dir))
		return (FALSE);
	return (TRUE);
}

int	ft_cd(int argc, const char **argv)
{
	if (argc > 2)
	{
		ft_putendl_fd("Too many arguments.", STDERR_FILENO);
		return (1);
	}
	if (argc == 1 || ft_strncmp(cur_dir, "/", 1) == 0)
	{
		g_shell.env = get_env(g_shell.env, "HOME");
		if (!set_dir(g_shell.env->value))
			return (1);
	}
	else
	{
		if (!set_dir(argv[1]))
			return (1);
	}
	return (0);
}

int	main(int argc, char const *argv[], char **envp)
{
	// char	*cur_dir;
	// t_env	*pwd;
	// t_env	*old_pwd;

	// parse_environment(envp);
	// pwd = get_env(g_shell.env, "PWD");
	// old_pwd = get_env(g_shell.env, "OLDPWD");
	// printf(BOLD GREEN"pwd: %s\nold pwd: %s\n", pwd->value, old_pwd->value);
	// ft_cd(argc + 1, &argv[1]);
	printf("%d\n",chdir(".."));
	return (0);
}
