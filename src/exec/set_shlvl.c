/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_shlvl.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 16:53:14 by buiterma      #+#    #+#                 */
/*   Updated: 2022/10/18 16:58:04 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	set_shlvl(void)
{
	t_env	*tmp;
	size_t	shlvl;

	tmp = get_env(g_shell.env, "SHLVL");
	shlvl = ft_atoi(tmp->value) + 1;
	set_env("SHLVL", ft_strdup(ft_itoa(shlvl)));
}
