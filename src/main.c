/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 20:43:40 by buiterma      #+#    #+#                 */
/*   Updated: 2022/08/31 20:38:40 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	main(void)
{
	char	*input;
	t_token	*tokens;
	t_shell	shell;

	while (isatty(STDIN_FILENO))
	{
		input = readline(BOLD BLUE SHELL RESET);
		if (!input)
			break ;
		tokens = lexer(input);
		shell = parser(tokens, input);
		add_history(input);
		print_command(shell.cmds, shell.cmd_n);
		if (!ft_strncmp(input, "exit", 4))
			break ;
	}
	free (input);
	input = NULL;
	return (0);
}
