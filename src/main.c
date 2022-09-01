/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 20:43:40 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/01 13:06:35 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*read_line(char *prompt)
{
	char	*input;

	if (isatty(STDIN_FILENO))
	{
		input = readline(prompt);
		if (input)
			add_history(input);
	}
	// else
	// {
	// 	input = ft_get_next_line(STDIN_FILENO);
	// }
	return (input);
}

int	main(void)
{
	char	*input;
	t_token	*tokens;
	t_shell	shell;

	while (1)
	{
		input = read_line(BOLD BLUE SHELL RESET);
		if (!input)
			break ;
		tokens = lexer(input);
		shell = parser(tokens, input);
		if (!ft_strncmp(input, "exit", 4))
			break ;
		free (input);
		input = NULL;
	}
	return (0);
}
