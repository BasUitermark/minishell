/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 20:43:40 by buiterma      #+#    #+#                 */
/*   Updated: 2022/10/25 12:04:36 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <termios.h>

void	free_program_data(void)
{
	close(g_shell.fd_in);
	purge_commands();
	clear_token_list(&g_shell.token);
	g_shell.cmd_n = 0;
	g_shell.cmds = NULL;
	g_shell.token = NULL;
}

static void	init(void)
{
	struct termios	t;

	g_shell.fd_in = -1;
	g_shell.fd_out = -1;
	set_shlvl();
	tcgetattr(STDIN_FILENO, &t);
	t.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &t);
	rl_catch_signals = false;
	set_signals();
}

t_shell	g_shell;

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

// static bool	shell_loop(void)
// {

// }

int	main(int argc, char **argv, char **envp)
{
	char			*input;

	argc = 0;
	argv = NULL;
	if (!parse_environment(envp))
		exit(EXIT_FAILURE);
	init();
	while (1)
	{
		input = sanitize(readline(BOLD BLUE SHELL RESET));
		if (!input)
		{
			free_program_data();
			exit
		}
		if (!lexer(input))
			exit(EXIT_FAILURE);
		if (!parser(input))
			exit(EXIT_FAILURE);
		add_history(input);
		if (!resolve_paths())
			exit(EXIT_FAILURE);
		if (!exec())
			exit(EXIT_FAILURE);
		free_program_data();
	}
	return (EXIT_SUCCESS);
}
