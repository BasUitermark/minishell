/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cd.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 13:34:33 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/08 16:28:57 by buiterma      ########   odam.nl         */
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

int	ft_cd(int argc, const char **argv)
{
	char	*temp_dir;

	getcwd(NULL, -1);
	if (argc < 2)
		return (1);
	if (ft_strncmp(argv[1], "..", 2) == 0 || ft_strncmp(argv[1], "../", 3) == 0)
		chdir(prev_dir(temp_dir));
	else
	{
		cur_dir = ft_strjoin(temp_dir, "/");
		cur_dir = ft_strappend(cur_dir, argv[1]);
		if (chdir(cur_dir) == 0)
		{
			ft_putstr_fd(cur_dir, STDERR_FILENO);
			ft_putendl_fd(": No such file or directory.", STDERR_FILENO);
		}
	}
	return (0);
}

int	main(int argc, char const *argv[])
{
	char	*cur_dir;

	ft_cd(argc + 1, &argv[1]);
	return (0);
}
