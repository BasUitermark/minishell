/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_echo.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 16:59:32 by buiterma      #+#    #+#                 */
/*   Updated: 2022/10/27 22:18:00 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	cmd_echo(int argc, const char **argv)
{
	int		i;
	t_env	*home;
	bool	newline;

	i = 1;
	newline = true;
	if (argc == 1)
		return (ft_putchar_fd('\n', 1) & 0);
	if (ft_strncmp((char *)argv[1], "-n", 2) == 0 && argc >= 2)
	{
		newline = false;
		i = 2;
	}
	else if (ft_strncmp((char *)argv[1], "~", 1) == 0)
	{
		home = get_env(g_shell.env, "HOME");
		if (!home)
		{
			ft_putendl_fd("bash: cd: HOME not set", 2);
			cleanup(NULL);
			return (1);
		}
		return (ft_putendl_fd(home->value, 1) & 0);
	}
	while (argv[i] && argc >= 2)
	{
		ft_putstr_fd((char *)argv[i], 1);
		if (argv[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (newline)
		ft_putchar_fd('\n', 1);
	return (0);
}
