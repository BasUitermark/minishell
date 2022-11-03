/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 20:43:40 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/03 12:52:14 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	cleanup(t_token *token, int exit)
{
	if (g_shell.fd_in > 2)
		close(g_shell.fd_in);
	if (g_shell.fd_out > 2)
		close(g_shell.fd_out);
	purge_commands();
	clear_token_list(&token);
	token = NULL;
	return (exit);
}

static void	init(void)
{
	if (g_shell.fd_in > 2)
		close(g_shell.fd_in);
	if (g_shell.fd_out > 2)
		close(g_shell.fd_out);
	g_shell.fd_in = STDIN_FILENO;
	g_shell.fd_out = STDOUT_FILENO;
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
	if (!inp)
	{
		free(inp);
		return (NULL);
	}
	return (inp);
}

static bool	shell_loop(char *input)
{
	t_token	*token;

	token = NULL;
	add_history(input);
	if (!lexer(&token, input) || !token || !parser(&token, input) \
		|| clear_token_list(&token) || !resolve_paths() || !exec())
	{
		free(input);
		cleanup(token, 0);
		return (false);
	}
	cleanup(token, 0);
	free(input);
	return (true);
}

int	main(int argc, char **argv, char **envp)
{
	char			*input;

	(void)argc;
	(void)argv;
	if (!parse_environment(envp))
		exit(EXIT_FAILURE);
	if (!set_shlvl())
		exit(cleanup(NULL, EXIT_FAILURE));
	while (1)
	{
		init();
		init_signal();
		input = readline(BOLD BLUE SHELL RESET);
		if (!input)
		{
			ft_putendl_fd("exit", STDOUT_FILENO);
			exit(cleanup(NULL, g_shell.exit_code));
		}
		input = sanitize(input);
		if (!input)
			continue ;
		if (!shell_loop(input))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
