/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 20:43:40 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/13 16:56:28 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	init(void)
{
	g_shell.fd_in = -1;
	g_shell.fd_out = STDOUT_FILENO;
}

//int	main(int argc, char **argv, char **envp)
//{
//	char	*input;

//	if (!parse_environment(envp))
//		exit(EXIT_FAILURE);
//	init();
//	while (true)
//	{
//		input = readline(BOLD BLUE SHELL RESET);
//		if (!input)
//			exit(EXIT_FAILURE);
//		if (!lexer(input))
//			exit(EXIT_FAILURE);
//		if (!parser(input))
//			exit(EXIT_FAILURE);
//		if (!resolve_paths())
//			exit(EXIT_FAILURE);
//		if (!ft_strncmp(input, "exit", 4))
//			break ;

//		add_history(input);
//		free (input);
//		input = NULL;
//		close(g_shell.fd_in);
//		close(g_shell.fd_out);
//		init();
//	}
//	return (EXIT_SUCCESS);
//}

// all exit() calls should be replaced with error functions
// call cleanup before return in main
// maybe make exit a builtin
// ls -la | grep "." | exit , should exit



int	main(int argc, char **argv, char **envp)
{
	char	*input;

	if (!parse_environment(envp))
		exit(EXIT_FAILURE);
	init();
	while (1)
	{
		printf("ayo?\n");
		input = readline(BOLD BLUE SHELL RESET);
		if (!input)
			exit(EXIT_FAILURE);
		printf("fr?\n");
		if (!lexer(input))
			exit(EXIT_FAILURE);
		printf("ong?\n");
		if (!parser(input))
			exit(EXIT_FAILURE);
		if (!resolve_paths())
			exit(EXIT_FAILURE);

		if (!ft_strncmp(input, "exit", 4))
			break ;

		if (!exec())
			exit(EXIT_FAILURE);

		add_history(input);
		free (input);
		input = NULL;
		if (g_shell.fd_in != STDIN_FILENO)
			close(g_shell.fd_in);
		if (g_shell.fd_out != STDOUT_FILENO)
			close(g_shell.fd_out);
		init();
	}
	return (EXIT_SUCCESS);
}
