/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 11:29:47 by buiterma      #+#    #+#                 */
/*   Updated: 2022/08/31 13:18:50 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	print__all_tokens(t_token *tokens)
{
	while (tokens != NULL)
	{
		printf("%d\n", tokens->index);
		printf("%d\n", tokens->length);
		printf("%d\n\n", tokens->type);
		tokens = tokens->next;
	}
}

void	print_token(t_token *token)
{
	printf("%d\n", token->index);
	printf("%d\n", token->length);
	printf("%d\n\n", token->type);
}

void	print_command(t_command *cmd, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (cmd[i].args[j])
		{
			printf("%s ", cmd[i].args[j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

static char	**parse_command(char *input, t_token *tokens, int amount)
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

t_command	*parser(size_t *n, t_token *tokens, char *input)
{
	size_t		i;
	size_t		arg_count;
	t_command	*cmds;

	i = 0;
	*n = command_counter(tokens);
	cmds = malloc(*n * sizeof(t_command));
	// if (!cmds)
	// 	error();
	while (tokens && i < *n)
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

int	main(void)
{
	t_token		*tokens;
	t_token		*temp;
	t_shell		shell;
	char		*input = "< Makefile cat | wc -w > outfile";

	tokens = NULL;
	tokens = (t_token *)malloc(3 * sizeof(t_token));
	tokens = token_lstnew(2, 8, in_file);
	token_lstadd_back(&tokens, token_lstnew(11, 3, command));
	token_lstadd_back(&tokens, token_lstnew(17, 2, command));
	token_lstadd_back(&tokens, token_lstnew(20, 2, argument));
	token_lstadd_back(&tokens, token_lstnew(25, 7, out_file));
	shell.cmds = parser(&shell.cmd_n, tokens, input);
	print_command(shell.cmds, shell.cmd_n);
	return (0);
}
