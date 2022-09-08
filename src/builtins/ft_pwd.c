/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pwd.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 11:17:12 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/08 12:37:55 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "shell.h"
#include "../../include/shell.h"
#include "../../libs/libft/include/libft.h"
#include <stdio.h>

int	ft_pwd(void)
{
	while (g_shell.env)
	{
		if (ft_strncmp(g_shell.env->key, "PWD", 3) == 0)
			ft_putendl_fd(g_shell.env->value, 1);
		g_shell.env = g_shell.env->next;
	}
	return (0);
}

int	main(int argc, char const *argv[], char **envp)
{
	g_shell.env = parse_environment(envp);
	ft_pwd();
	return (0);
}
