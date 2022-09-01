/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_commands.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 13:30:56 by buiterma      #+#    #+#                 */
/*   Updated: 2022/08/31 19:49:28 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static size_t	command_counter(t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens)
	{
		if (tokens->type == COMMAND)
			i++;
		tokens = tokens->next;
	}
	return (i);
}

static size_t	arg_counter(t_token *tokens)
{
	int	i;

	i = 1;
	tokens = tokens->next;
	while (tokens && tokens->type == ARGUMENT)
	{
		i++;
		tokens = tokens->next;
	}
	return (i);
}

static char	**parse_args(char const *input, t_token *tokens, int amount)
{
	char	**args;
	size_t	i;

	i = 0;
	args = ft_calloc(amount + 1, sizeof(char *));
	// if (!args)
	// 	error();
	while (tokens && i < amount)
	{
		args[i] = ft_substr(input, tokens->index, tokens->length);
		i++;
		tokens = tokens->next;
	}
	return (args);
}

void	parse_commands(t_shell *shell, t_token *tokens, char const *input)
{
	size_t		i;
	size_t		arg_count;

	i = 0;
	shell->cmd_n = command_counter(tokens);
	shell->cmds = malloc(shell->cmd_n * sizeof(t_command));
	// if (!cmds)
	// 	error();
	while (tokens && i < shell->cmd_n)
	{
		if (tokens->type == COMMAND)
		{
			arg_count = arg_counter(tokens);
			shell->cmds[i].args = parse_args(input, tokens, arg_count);
			i++;
		}
		tokens = tokens->next;
	}
}
