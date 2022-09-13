/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_unset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 17:09:16 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/13 09:58:21 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
// #include "../../include/shell.h"
// #include "../../libs/libft/include/libft.h"
// #include <stdio.h>

static char	*find_key(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		i++;
	}
	return (ft_substr(str, 0, i));
}

int	cmd_unset(int argc, const char **argv)
{
	char	*key;
	int		i;

	i = 0;
	while (g_shell.env)
	{
		key = find_key(argv[i]);
		if (!remove_variable(&g_shell.env, key))
		{
			free(key);
			return (1);
		}
		free(key);
		g_shell.env = g_shell.env->next;
		i++;
	}
	return (0);
}
