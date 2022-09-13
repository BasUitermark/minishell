/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_export.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/12 16:39:37 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/13 09:57:16 by buiterma      ########   odam.nl         */
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

static char	*find_value(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		i++;
	}
	return (ft_substr(str, i + 1, ft_strlen(str)));
}

int	cmd_export(int argc, const char **argv)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	if (argc < 1)
		return (1);
	while (i < argc)
	{
		key = find_key(argv[i]);
		value = find_value(argv[i]);
		if (!set_env(key, value))
		{
			free (key);
			free (value);
			return (1);
		}
		free (key);
		free (value);
		i++;
	}
	return (0);
}
