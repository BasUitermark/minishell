/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 20:43:40 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/06 12:27:21 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	init(void)
{
	g_shell.fd_in = -1;
	g_shell.fd_out = -1;
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;

	if (!parse_environment(envp))
		exit(EXIT_FAILURE);
	init();
	while (1)
	{
		input = readline(BOLD BLUE SHELL RESET);
		if (!input)
			exit(EXIT_FAILURE);
		if (!ft_strncmp(input, "exit", 4))
			break ;
		add_history(input);
		g_shell.token = lexer(input);
		parser(tokens, input);
		free (input);
		input = NULL;
		close(g_shell.fd_in);
		close(g_shell.fd_out);
		init();
	}
	// cleanup
	return (EXIT_SUCCESS);
}

// all exit() calls should be replaced with error functions
