/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 20:43:40 by buiterma      #+#    #+#                 */
/*   Updated: 2022/10/31 10:44:29 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	cleanup(t_token *token)
{
	purge_commands();
	clear_token_list(&token);
	token = NULL;
}

static void	init(void)
{
	if (g_shell.fd_in > 2)
		close(g_shell.fd_in);
	if (g_shell.fd_out > 2)
		close(g_shell.fd_out);
	g_shell.fd_in = STDIN_FILENO;
	g_shell.fd_out = STDOUT_FILENO;
	set_shlvl();
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

static void	shell_loop(char *input)
{
	t_token	*token;

	token = NULL;
	add_history(input);
	if (!lexer(&token, input))
	{
		cleanup(NULL);
		return ;
	}
	if (!token)
	{
		free (input);
		return ;
	}
	if (!parser(&token, input))
	{
		cleanup(token);
		return ;
	}
	clear_token_list(&token);
	if (!resolve_paths())
	{
		cleanup(NULL);
		return ;
	}
	if (!exec())
	{
		cleanup(NULL);
		return ;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char			*input;

	argc = 0;
	argv = NULL;
	if (!parse_environment(envp))
		exit(EXIT_FAILURE);
	while (1)
	{
		init();
		init_signal();
		input = readline(BOLD BLUE SHELL RESET);
		if (!input)
		{
			cleanup(NULL);
			ft_putendl_fd("exit", STDOUT_FILENO);
			exit(g_shell.exit_code);
		}
		input = sanitize(input);
		if (!input)
			continue ;
		shell_loop(input);
	}
	return (EXIT_SUCCESS);
}
