/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_special.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 19:49:14 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/17 14:05:05 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static bool	parse_infile(t_token *tokens, char const *input, t_command *cmd)
{
	char	*tmp_path;

	if (cmd->fd_in < 0)
		return (true);
	if (cmd->fd_in != STDIN_FILENO)
	{
		close(cmd->fd_in);
		cmd->fd_in = STDIN_FILENO;
	}
	tmp_path = ft_substr(input, tokens->index, tokens->length);
	if (!tmp_path)
		return (false);
	cmd->fd_in = open(tmp_path, O_RDONLY);
	if (cmd->fd_in < 0)
		error("minishell", tmp_path, \
		"No such file or directory", 1);
	free (tmp_path);
	return (true);
}

static bool	parse_outfile(t_token *tokens, char const *input, t_command *cmd)
{
	char	*tmp_path;

	if (cmd->fd_out < 0 || cmd->fd_in < 0)
		return ;
	if (cmd->fd_out != STDOUT_FILENO)
	{
		close(cmd->fd_out);
		cmd->fd_out = STDOUT_FILENO;
	}
	tmp_path = ft_substr(input, tokens->index, tokens->length);
	if (tokens->type == OUTFILE)
		cmd->fd_out = open(tmp_path, O_RDWR | O_CREAT | O_TRUNC, \
						0644);
	if (tokens->type == OUTFILE_APPEND)
		cmd->fd_out = open(tmp_path, O_RDWR | O_CREAT | O_APPEND, \
						0644);
	free (tmp_path);
	return (cmd->fd_out >= 0);
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
		{
			free(tmp);
			break ;
		}
		if (!expand(&tmp))
		{
			free(tmp);
			break ;
		}
		ft_putstr_fd(tmp, pipe[WRITE]);
		free(tmp);
	}
}

static void	parse_heredoc(t_token token, char const *input, t_command *cmd)
{
	char	*end;
	int		pipe[2];

	end = NULL;
	end = ft_substr(input, token.index, token.length);
	if (!end || !ft_pipe(pipe))
		return ((void)free(end));
	if (cmd->fd_in != STDIN_FILENO)
	{
		close(cmd->fd_in);
		cmd->fd_in = STDIN_FILENO;
	}
	cmd->fd_in = pipe[READ];
	heredoc_loop(pipe, end);
	close(pipe[WRITE]);
	free(end);
}

// bool	parse_special(t_token *tokens, char const *input)
// {
// 	while (tokens)
// 	{
// 		if (tokens->type == HEREDOC)
// 			parse_heredoc(*tokens, input);
// 		if (tokens->type == INFILE)
// 			parse_infile(tokens, input);
// 		if (tokens->type == OUTFILE || tokens->type == OUTFILE_APPEND)
// 			parse_outfile(tokens, input);
// 		tokens = tokens->next;
// 	}
// }

bool	parse_special(t_token *tokens, char const *input)
{
	size_t	cmd_index;

	cmd_index = 0;
	while (tokens && g_shell.cmd_n)
	{
		if (tokens->type == HEREDOC)
			parse_heredoc(*tokens, input, &g_shell.cmds[cmd_index]);
		if (tokens->type == INFILE)
			if (!parse_infile(tokens, input, &g_shell.cmds[cmd_index]))
				return (false);
		if (tokens->type == OUTFILE || tokens->type == OUTFILE_APPEND)
			if (!parse_outfile(tokens, input, &g_shell.cmds[cmd_index]))
				return (false);
		tokens = tokens->next;
		if (tokens && tokens->type == PIPE && g_shell.cmd_n > cmd_index)
			cmd_index++;
	}
	return (true);
}
