/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_env.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 13:37:03 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/08 14:01:12 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "shell.h"
#include "../../include/shell.h"
#include "../../libs/libft/include/libft.h"
#include <stdio.h>

int	ft_env(void)
{
	if (!g_shell.env)
		return (1);
	while (g_shell.env)
	{
		ft_putstr_fd(g_shell.env->key, 1);
		ft_putchar_fd('=', 1);
		ft_putendl_fd(g_shell.env->value, 1);
		g_shell.env = g_shell.env->next;
	}
	return (0);
}
