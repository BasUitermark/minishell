/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 20:43:40 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/15 11:37:28 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	free_program_data(void)
{
	// close(g_shell.fd_in);
	purge_commands();
	clear_token_list(&g_shell.token);
}

static void	init(void)
{
	g_shell.fd_in = -1;
	g_shell.fd_out = -1;
}

//Fix env not working after unset & write exit
void	builtin_test(void)
{
	if (ft_strncmp(g_shell.cmds[0].args[0], "pwd", 3) == 0)
		cmd_pwd();
	else if (ft_strncmp(g_shell.cmds[0].args[0], "cd", 2) == 0)
		cmd_cd(ft_arraylen(g_shell.cmds[0].args), (const char **)g_shell.cmds[0].args);
	else if (ft_strncmp(g_shell.cmds[0].args[0], "env", 3) == 0)
		cmd_env();
	else if (ft_strncmp(g_shell.cmds[0].args[0], "export", 6) == 0)
		cmd_export(ft_arraylen(g_shell.cmds[0].args), (const char **)g_shell.cmds[0].args);
	else if (ft_strncmp(g_shell.cmds[0].args[0], "echo", 4) == 0)
		cmd_echo(ft_arraylen(g_shell.cmds[0].args), (const char **)g_shell.cmds[0].args);
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;

	if (!parse_environment(envp))
		exit(EXIT_FAILURE);
	while (true)
	{
		init();
		input = readline(BOLD BLUE SHELL RESET);
		if (!input || !lexer(input) || !parser(input) || !resolve_paths())
			exit(EXIT_FAILURE);
		builtin_test();
		add_history(input);
		free(input);
		free_program_data();
	}
	// clear_list(&g_shell.env);
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