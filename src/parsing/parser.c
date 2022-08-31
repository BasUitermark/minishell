/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 11:29:47 by buiterma      #+#    #+#                 */
/*   Updated: 2022/08/31 20:35:05 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_shell	parser(t_token *tokens, char const *input)
{
	t_shell	shell;

	parse_commands(&shell, tokens, input);
	parse_special(&shell, tokens, input);
	return (shell);
}
