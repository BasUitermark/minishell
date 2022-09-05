/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_special.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 19:49:14 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/05 10:29:23 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	parse_infile(t_token *tokens, char const *input)
{
	int		fd;
	char	*tmp_path;

	fd = 0;
	while (tokens)
	{
		if (tokens->type == INFILE)
		{
			tmp_path = ft_substr(input, tokens->index, tokens->length);
			if (access(tmp_path, R_OK))
				fd = open(tmp_path, O_RDONLY);
			free (tmp_path);
		}
		tokens = tokens->next;
	}
	return (fd);
}

static int	parse_outfile(t_token *tokens, char const *input)
{
	int		fd;
	char	*tmp_path;

	fd = 0;
	while (tokens)
	{
		if (tokens->type == OUTFILE || tokens->type == OUTFILE_APPEND)
		{
			tmp_path = ft_substr(input, tokens->index, tokens->length);
			if (access(tmp_path, R_OK && tokens->type == OUTFILE))
				fd = open(tmp_path, O_RDWR | O_CREAT | O_TRUNC, 0644);
			if (access(tmp_path, R_OK && tokens->type == OUTFILE_APPEND))
				fd = open(tmp_path, O_RDWR | O_CREAT | O_APPEND, 0644);
			free (tmp_path);
		}
		tokens = tokens->next;
	}
	return (fd);
}

static char	*parse_heredoc(t_token token, char const *input)
{
	char	*tmp;
	char	*str;
	char	*end;

	end = ft_substr(input, token.index, token.length);
	str = NULL;
	while (1)
	{
		write(1, "> ", 2);
		tmp = ft_get_next_line(STDIN_FILENO);
		if (!tmp || !ft_strncmp(tmp, end, ft_strlen(end)))
			break ;
		str = ft_strappend(str, tmp);
		free(tmp);
	}
	free(end);
	return (str);
}

void	parse_special(t_shell *shell, t_token *tokens, char const *input)
{
	char	*heredoc;

	while (tokens)
	{
		if (tokens->type == HEREDOC)
			heredoc = parse_heredoc(*tokens, input);
		if (tokens->type == INFILE)
			shell->fd_in = parse_infile(tokens, input);
		if (tokens->type == OUTFILE || tokens->type == OUTFILE_APPEND)
			shell->fd_out = parse_outfile(tokens, input);
		tokens = tokens->next;
	}
}
