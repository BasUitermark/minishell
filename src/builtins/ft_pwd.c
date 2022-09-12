/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pwd.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 11:17:12 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/08 13:34:46 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_pwd(void)
{
	g_shell.env = get_env(g_shell.env, "PWD");
	if (!(ft_strncmp(g_shell.env->key, "PWD", 3) == 0))
		return (1);
	ft_putendl_fd(g_shell.env->value, 1);
	return (0);
}
