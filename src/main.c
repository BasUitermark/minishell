/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 20:43:40 by buiterma      #+#    #+#                 */
/*   Updated: 2022/08/31 16:35:33 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	main(void)
{
	char	*input_line;
	t_token	*tokens;
	t_shell	shell;

	while (1)
	{
		input_line = readline(BOLD BLUE SHELL RESET);
		tokens = lexer(input_line);
		shell = parser(tokens, input_line);
		add_history(input_line);
		print_command(shell.cmds, shell.cmd_n);
		if (!ft_strncmp(input_line, "exit", 4))
			break ;
	}
	free (input_line);
	input_line = NULL;
	return (0);
}
