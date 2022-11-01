/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_shlvl.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 16:53:14 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/01 14:38:49 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	set_shlvl(void)
{
	t_env	*tmp;
	size_t	shlvl;
	char	*lvl_dup;
	char	*convert;

	tmp = get_env(g_shell.env, "SHLVL");
	shlvl = ft_atoi(tmp->value) + 1;
	convert = ft_itoa(shlvl);
	lvl_dup = ft_strdup(convert);
	free (convert);
	if (!set_env("SHLVL", lvl_dup))
		exit(1);
}
