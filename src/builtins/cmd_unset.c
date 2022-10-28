/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_unset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 17:09:16 by buiterma      #+#    #+#                 */
/*   Updated: 2022/10/28 21:26:46 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	*find_key(const char *str)
{
	int		i;
	char	*key;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		i++;
	}
	key = ft_substr(str, 0, i);
	if (!key)
		return (NULL);
	return (key);
}

int	cmd_unset(int argc, const char **argv)
{
	char	*key;
	int		i;

	argc = 0;
	i = 0;
	while (g_shell.env && argv[i])
	{
		key = find_key(argv[i]);
		if (!key)
			return (EXIT_FAILURE);
		if (!remove_variable(&g_shell.env, key))
		{
			free(key);
			return (EXIT_FAILURE);
		}
		free(key);
		g_shell.env = g_shell.env->next;
		i++;
	}
	return (EXIT_SUCCESS);
}
