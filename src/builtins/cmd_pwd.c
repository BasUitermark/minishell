/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_pwd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 11:17:12 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/13 16:50:13 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	cmd_pwd(void)
{
	t_env	*pwd;

	pwd = get_env(g_shell.env, "PWD");
	if (!(ft_strncmp(pwd->key, "PWD", 3) == 0))
		return (1);
	ft_putendl_fd(pwd->value, 1);
	return (0);
}
