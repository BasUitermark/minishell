/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 20:43:40 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/05 15:57:12 by buiterma      ########   odam.nl         */
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
	t_token	*tokens;

	g_shell.env = parse_environment(envp);
	init();
	while (1)
	{
		input = readline(BOLD BLUE SHELL RESET);
		if (!input)
			break ;
		add_history(input);
		tokens = lexer(input);
		parser(tokens, input);
		if (!ft_strncmp(input, "exit", 4))
			break ;
		free (input);
		input = NULL;
		close(g_shell.fd_in);
		close(g_shell.fd_out);
		init();
	}
	return (0);
}
