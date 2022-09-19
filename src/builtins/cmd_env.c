/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_env.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 13:37:03 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/19 11:08:20 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	cmd_env(void)
{
	t_env	*env;

	env = g_shell.env;
	if (!env)
		return (1);
	while (env)
	{
		ft_putstr_fd(env->key, 1);
		ft_putchar_fd('=', 1);
		ft_putendl_fd(env->value, 1);
		env = env->next;
	}
	return (0);
}
