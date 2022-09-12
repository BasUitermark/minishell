/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 20:43:40 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/12 14:54:49 by jde-groo      ########   odam.nl         */
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
	while (true)
	{
		input = readline(BOLD BLUE SHELL RESET);
		if (!input)
			exit(EXIT_FAILURE);
		if (!lexer(input))
			exit(EXIT_FAILURE);
		if (!parser(input))
			exit(EXIT_FAILURE);
		if (!resolve_paths())
			exit(EXIT_FAILURE);
		if (!ft_strncmp(input, "exit", 4))
			break ;

		add_history(input);
		free (input);
		input = NULL;
		close(g_shell.fd_in);
		close(g_shell.fd_out);
		init();
	}
	return (EXIT_SUCCESS);
}

// all exit() calls should be replaced with error functions
// call cleanup before return in main
// maybe make exit a builtin
// ls -la | grep "." | exit , should exit



//int	main(int argc, char **argv, char **envp)
//{
//	char	*input;

//	if (!parse_environment(envp))
//		exit(EXIT_FAILURE);
//	init();
//	while (1)
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

//		int index = 0;
//		while (index < g_shell.cmd_n)
//		{
//			printf("[%d] %s -> %s \n", index, g_shell.cmds[index].args[0], g_shell.cmds[index].path);
//			int i = 0;
//			while (g_shell.cmds[index].args[i])
//			{
//				printf("\t[%d] %s \n", i, g_shell.cmds[index].args[i]);
//				i++;
//			}
//			index++;
//		}


//		add_history(input);
//		free (input);
//		input = NULL;
//		close(g_shell.fd_in);
//		close(g_shell.fd_out);
//		init();
//	}
//	return (EXIT_SUCCESS);
//}