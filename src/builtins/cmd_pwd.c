/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_pwd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 11:17:12 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/24 14:14:07 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	cmd_pwd(void)
{
	char	*pwd;
	t_env	*lst_pwd;

	lst_pwd = get_env(g_shell.env, "PWD");
	if (lst_pwd)
	{
		ft_putendl_fd(lst_pwd->value, 1);
		return (0);
	}
	pwd = getenv("PWD");
	if (!pwd)
		return (1);
	ft_putendl_fd(pwd, 1);
	return (0);
}
