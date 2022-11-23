/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_pwd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 11:17:12 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/23 16:09:02 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	cmd_pwd(void)
{
	char	*pwd;

	pwd = getenv("PWD");
	if (!pwd)
		return (1);
	ft_putendl_fd(pwd, 1);
	return (0);
}
