/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_env.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 13:37:03 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/01 13:18:38 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	cmd_env(int argc, const char **argv)
{
	t_env	*env;

	if (argc > 1)
		return (error("env", (char *)argv[1], \
			"No such file or directory", 127));
	env = g_shell.env;
	if (!env)
		return (1);
	while (env)
	{
		if (!env->hidden)
		{
			ft_putstr_fd(env->key, 1);
			ft_putchar_fd('=', 1);
			ft_putendl_fd(env->value, 1);
		}
		env = env->next;
	}
	return (0);
}
