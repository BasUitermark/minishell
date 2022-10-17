/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 20:43:40 by buiterma      #+#    #+#                 */
/*   Updated: 2022/10/14 15:28:34 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	init(void)
{
	if (g_shell.fd_in > 2)
		close(g_shell.fd_in);
	if (g_shell.fd_out > 2)
		close(g_shell.fd_out);
	g_shell.fd_in = STDIN_FILENO;
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

static char	*sanitize(char *inp)
{
	int	index;

	if (!inp)
		return (NULL);
	index = 0;
	while (inp[index])
		index++;
	index--;
	while (index >= 0)
	{
		if (!ft_strchr("\t ", inp[index]))
			break ;
		inp[index] = '\0';
		index--;
	}
	if (!inp[0])
	{
		free(inp);
		return (NULL);
	}
	return (inp);
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;

	if (!parse_environment(envp))
		exit(EXIT_FAILURE);
	while (1)
	{
		init();
		input = sanitize(readline(BOLD BLUE SHELL RESET));
		if (!input)
			continue ;
		if (!lexer(input))
			exit(EXIT_FAILURE);
		if (!parser(input))
			exit(EXIT_FAILURE);
		add_history(input);
		free (input);
		input = NULL;
		if (!resolve_paths())
			exit(EXIT_FAILURE);
		if (!exec())
			exit(EXIT_FAILURE);
		g_shell.cmd_n = 0;
		g_shell.cmds = NULL;
		g_shell.token = NULL;
	}
	return (EXIT_SUCCESS);
}
