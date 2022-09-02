/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 20:43:40 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/02 12:22:35 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input_line;
	t_token	*tokens;
	t_shell	shell;

	shell.env = parse_environment(envp);
	while (1)
	{
		input_line = readline(BOLD BLUE SHELL RESET);
		tokens = lexer(input_line);
		shell = parser(tokens, input_line);
		add_history(input_line);
		if (ft_strncmp(input_line, "exit", 4))
			break ;
	}
	free (input_line);
	input_line = NULL;
	return (0);
}
