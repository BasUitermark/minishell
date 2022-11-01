/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_echo.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 16:59:32 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/01 19:15:07 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static bool	is_flag(const char *argv)
{
	size_t	i;

	i = 1;
	if (argv[0] != '-')
		return (FALSE);
	while (argv[i])
	{
		if (argv[i] != 'n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static void	print_all(int argc, const char **argv, int i)
{
	while (argv[i] && argc >= 2 && i != argc)
	{
		ft_putstr_fd((char *)argv[i], 1);
		if (argv[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
}

int	cmd_echo(int argc, const char **argv)
{
	int		i;
	char	*tmp;
	bool	newline;

	i = 1;
	newline = true;
	if (argc == 1)
		return (ft_putchar_fd('\n', 1) & 0);
	while (argv[i] && is_flag(argv[i]) && argc >= 2)
		i++;
	if (i > 1)
		newline = FALSE;
	if (ft_strncmp((char *)argv[1], "~", 1) == 0)
	{
		tmp = getenv("HOME");
		if (!tmp)
			return (1);
		ft_putendl_fd(tmp, 1);
		return (0);
	}
	print_all(argc, argv, i);
	if (newline)
		ft_putchar_fd('\n', 1);
	return (0);
}
