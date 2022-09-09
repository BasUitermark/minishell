/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cd.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 13:34:33 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/09 19:56:41 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "shell.h"
#include "../../include/shell.h"
#include "../../libs/libft/include/libft.h"
#include <stdio.h>

static char	*prev_dir(char *cur_dir)
{
	int		len;
	char	*prev_dir;

	len = ft_strlen(cur_dir);
	if (ft_strncmp(cur_dir, "/", 1) == 0 && ft_strlen(cur_dir) == 1)
		return (cur_dir);
	while (len > 0)
	{
		if (cur_dir[len] == '/')
			break ;
		len--;
	}
	prev_dir = ft_substr(cur_dir, 0, len);
	if (!prev_dir)
		return (NULL);
	return (prev_dir);
}

// Set PWD and OLDPWD to correct values after performing CD.
// Clean up function for readability.
int	ft_cd(int argc, const char **argv)
{
	char	*temp_dir;
	char	*cur_dir;

	cur_dir = getcwd(NULL, -1);
	if (argc < 2)
		return (1);
	if (ft_strncmp(argv[1], "..", 2) == 0 || ft_strncmp(argv[1], "../", 3) == 0)
		chdir(prev_dir(cur_dir));
	// else
	// {
	// 	cur_dir = ft_strjoin(temp_dir, "/");
	// 	cur_dir = ft_strappend(cur_dir, argv[1]);
	// 	if (chdir(cur_dir) == 0)
	// 	{
	// 		ft_putstr_fd(cur_dir, STDERR_FILENO);
	// 		ft_putendl_fd(": No such file or directory.", STDERR_FILENO);
	// 	}
	// }
	return (0);
}

int	main(int argc, char const *argv[], char **envp)
{
	char	*cur_dir;
	t_env	*pwd;
	t_env	*old_pwd;

	parse_environment(envp);
	pwd = get_env(g_shell.env, "PWD");
	old_pwd = get_env(g_shell.env, "OLDPWD");
	printf("pwd: %s\nold pwd: %s\n", pwd->value, old_pwd->value);
	ft_cd(argc + 1, &argv[1]);
	return (0);
}
