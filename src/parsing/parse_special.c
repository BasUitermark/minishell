/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_special.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 19:49:14 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/01 13:31:35 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	parse_infile(t_token *tokens, char const *input)
{
	char	*tmp_path;

	if (g_shell.fd_in != STDIN_FILENO)
	{
		close(g_shell.fd_in);
		g_shell.fd_in = STDIN_FILENO;
	}
	tmp_path = ft_substr(input, tokens->index, tokens->length);
	if (access(tmp_path, R_OK) == 0)
		g_shell.fd_in = open(tmp_path, O_RDONLY);
	free (tmp_path);
}

static void	parse_outfile(t_token *tokens, char const *input)
{
	char	*tmp_path;

	if (g_shell.fd_out != STDOUT_FILENO)
	{
		close(g_shell.fd_out);
		g_shell.fd_out = STDOUT_FILENO;
	}
	tmp_path = ft_substr(input, tokens->index, tokens->length);
	if (tokens->type == OUTFILE)
		g_shell.fd_out = open(tmp_path, O_RDWR | O_CREAT | O_TRUNC, \
						0644);
	if (tokens->type == OUTFILE_APPEND)
		g_shell.fd_out = open(tmp_path, O_RDWR | O_CREAT | O_APPEND, \
						0644);
	free (tmp_path);
}

static void	heredoc_loop(int *pipe, char *end)
{
	char	*tmp;

	while (1)
	{
		write(1, "> ", 2);
		tmp = ft_get_next_line(STDIN_FILENO);
		if (!tmp || (ft_strlen(tmp) == ft_strlen(end) + 1 \
			&& ft_strncmp(tmp, end, ft_strlen(end)) == 0))
			break ;
		if (!expand(&tmp))
		{
			free (tmp);
			break ;
		}
		ft_putstr_fd(tmp, pipe[WRITE]);
		free(tmp);
	}
}

static void	parse_heredoc(t_token token, char const *input)
{
	char	*end;
	int		pipe[2];

	end = NULL;
	end = ft_substr(input, token.index, token.length);
	if (!end || !ft_pipe(pipe))
		return ((void)free(end));
	if (g_shell.fd_in != STDIN_FILENO)
	{
		close(g_shell.fd_in);
		g_shell.fd_in = STDIN_FILENO;
	}
	g_shell.fd_in = pipe[READ];
	heredoc_loop(pipe, end);
	close(pipe[WRITE]);
	free(end);
}

void	parse_special(t_token *tokens, char const *input)
{
	while (tokens)
	{
		if (tokens->type == HEREDOC)
			parse_heredoc(*tokens, input);
		if (tokens->type == INFILE)
			parse_infile(tokens, input);
		if (tokens->type == OUTFILE || tokens->type == OUTFILE_APPEND)
			parse_outfile(tokens, input);
		tokens = tokens->next;
	}
}
