/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 11:29:47 by buiterma      #+#    #+#                 */
/*   Updated: 2022/08/31 15:51:30 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	print_all_tokens(t_token *tokens)
{
	while (tokens != NULL)
	{
		printf("%d\n", tokens->index);
		printf("%d\n", tokens->length);
		printf("%d\n", tokens->type);
		printf("%d\n", tokens->expendable);
		printf("%d\n\n", tokens->adjecent);
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

t_shell	parser(t_token *tokens, char const *input)
{
	t_shell	shell;

	// if (tokens->type == in_file || tokens->type == out_file || \
	// 	tokens->type == heredoc || tokens->type == out_file_append)
	// 	parse_special(shell, tokens, input);
	
	parse_commands(&shell, tokens, input);
	return (shell);
}

int	main(void)
{
	t_token		*tokens;
	t_token		token;
	t_token		*temp;
	t_shell		shell;
	char		*input;

	tokens = NULL;
	tokens = (t_token *)malloc(3 * sizeof(t_token));
	token.index = 2;
	token.length = 8;
	token.type = in_file;
	token.expendable = false;
	token.adjecent = false;
	tokens = token_lstnew(token);
	token.index = 11;
	token.length = 3;
	token.type = command;
	token.expendable = false;
	token.adjecent = false;
	token_lstadd_back(&tokens, token_lstnew(token));
	token.index = 17;
	token.length = 2;
	token.type = command;
	token.expendable = false;
	token.adjecent = false;
	token_lstadd_back(&tokens, token_lstnew(token));
	token.index = 20;
	token.length = 2;
	token.type = argument;
	token.expendable = false;
	token.adjecent = false;
	token_lstadd_back(&tokens, token_lstnew(token));
	token.index = 25;
	token.length = 7;
	token.type = out_file;
	token.expendable = false;
	token.adjecent = false;
	token_lstadd_back(&tokens, token_lstnew(token));
	while (1)
	{
		// input = readline(BOLD BLUE SHELL RESET);
		input = "< Makefile cat | wc -w > outfile";
		shell = parser(tokens, input);
		print_command(shell.cmds, shell.cmd_n);
		add_history(input);
		if (ft_strncmp(input, "exit", 4))
			break ;
	}
	free (input);
	input = NULL;
	return (0);
}
