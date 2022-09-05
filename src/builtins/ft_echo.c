/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_echo.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 16:59:32 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/05 17:15:54 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_echo(int argc, char **argv)
{
	int		i;
	bool	newline;

	i = 1;
	newline = true;
	if (ft_strncmp(argv[1], "-n", 2))
	{
		newline = false;
		i = 2;
	}
	while (argv[i])
	{
		
		i++;
	}
}
