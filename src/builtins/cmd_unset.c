/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_unset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 17:09:16 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/23 17:08:34 by jde-groo      ########   odam.nl         */
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

static bool	is_valid_key(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (false);
	if (!ft_isalpha(str[index]) && str[index] != '_')
		return (false);
	while (str[index] && str[index] != '=')
	{
		if (!ft_isalnum(str[index]) && str[index] != '_')
			return (false);
		index++;
	}
	return (true);
}

int	cmd_unset(int argc, const char **argv)
{
	char	*key;
	int		i;
	int		ret;

	(void)argc;
	i = -1;
	ret = EXIT_SUCCESS;
	while (g_shell.env && argv[i + 1])
	{
		i++;
		key = find_key(argv[i]);
		if (!key)
			return (EXIT_FAILURE);
		if (!is_valid_key((char *)argv[i]))
		{
			error("unset", (char *) argv[i], "not a valid identifier", 1);
			free(key);
			ret = EXIT_FAILURE;
			continue ;
		}
		remove_variable(&g_shell.env, key);
		free(key);
	}
	return (ret);
}
