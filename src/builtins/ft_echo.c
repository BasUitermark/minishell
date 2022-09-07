/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_echo.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 16:59:32 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/07 16:20:25 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "shell.h"
#include "../../libs/libft/include/libft.h"
#include <stdio.h>

int	ft_echo(int argc, char **str)
{
	int		i;
	bool	newline;

	i = 1;
	newline = true;
	// if (argc == 1)
	// 	return (ft_putchar_fd('\n', 1));
	if (ft_strncmp(str[1], "-n", 2) == 0 && argc >= 2)
	{
		newline = false;
		i = 2;
	}
	while (str[i] && argc >= 2)
	{
		ft_putstr_fd(str[i], 1);
		if (str[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (newline || argc == 2)
		ft_putchar_fd('\n', 1);
	return(0);
}


int main(int argc, char *argv[])
{
	char	**str;

	str = ft_split("echo", ' ');
	ft_echo(1, str);
	return 0;
}
