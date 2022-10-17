/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 20:43:40 by buiterma      #+#    #+#                 */
/*   Updated: 2022/10/17 12:08:00 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	free_program_data(void)
{
	close(g_shell.fd_in);
	purge_commands();
	clear_token_list(&g_shell.token);
}

static void	init(void)
{
	g_shell.fd_in = -1;
	g_shell.fd_out = -1;
}

t_shell	g_shell;

int	main(int argc, char **argv, char **envp)
{
	char	*input;

	if (argc > 1)
		return (EXIT_FAILURE);
	if (!parse_environment(envp))
		exit(EXIT_FAILURE);
	while (true)
	{
		init();
		signal_intercept();
		// signal(SIGINT, sighandler);
		// signal(SIGQUIT, sighandler);
		input = readline(BOLD BLUE SHELL RESET);
		if (!input || !lexer(input) || !parser(input))
			exit(EXIT_FAILURE);
		add_history(input);
		builtin_test();
		free(input);
		resolve_paths();
		free_program_data();
		system("leaks minishell");
	}
	return (EXIT_SUCCESS);
}
