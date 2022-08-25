/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 11:29:47 by buiterma      #+#    #+#                 */
/*   Updated: 2022/08/25 16:52:48 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static size_t	command_counter(t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens)
	{
		if (tokens->type == command)
			i++;
		tokens = tokens->next;
	}
	return (i);
}

static size_t	arg_counter(t_token *tokens)
{
	int	i;

	i = 0;
	tokens = tokens->next;
	while (tokens && tokens->type == argument)
	{
		i++;
		tokens = tokens->next;
	}
	return (i);
}

static char	**parse_command(char *input, t_token *tokens, int amount)
{
	char	**args;
	size_t	i;

	i = 0;
	args = malloc(amount * sizeof(char *));
	if (!args)
		error();
	while (i < amount)
	{
		args[i] = ft_substr(input, tokens->index, tokens->length);
		i++;
	}
	return (args);
}

t_command	*parser(t_token	*tokens, char *input)
{
	t_command	*cmds;
	size_t		i;
	size_t		len;
	size_t		command_count;
	size_t		arg_count;

	i = 0;
	command_count = command_counter(tokens);
	cmds = malloc(command_count * sizeof(t_command));
	if (!cmds)
		error();
	while (tokens && i < command_count)
	{
		if (tokens->type == command)
		{
			arg_count = arg_counter(tokens);
			cmds[i].args = parse_command(input, tokens, arg_count);
			i++;
		}
		tokens = tokens->next;
	}
	return (cmds);
}

int	main(int argc, char const *argv[])
{
	t_token *tokens;
	

	tokens = malloc(2 * sizeof(t_token));

	return 0;
}
