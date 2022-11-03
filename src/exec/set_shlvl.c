/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_shlvl.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 16:53:14 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/03 12:53:01 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static bool	init_shlvl()
{
	char	*convert;

	convert = ft_itoa(1);
	if (!convert)
		return (false);
	if (!set_env("SHLVL", convert))
	{
		free(convert);
		return (false);
	}
	return (true);
}

bool	set_shlvl(void)
{
	t_env	*tmp;
	size_t	shlvl;
	char	*convert;

	tmp = get_env(g_shell.env, "SHLVL");
	if (!tmp)
		return (init_shlvl());
	shlvl = ft_atoi(tmp->value) + 1;
	convert = ft_itoa(shlvl);
	if (!convert)
		return (false);
	if (!set_env("SHLVL", convert))
	{
		free(convert);
		return (false);
	}
	return (true);
}
