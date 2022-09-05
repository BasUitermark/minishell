/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 11:29:47 by buiterma      #+#    #+#                 */
/*   Updated: 2022/09/05 13:41:56 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

bool	parser(t_token *tokens, char const *input)
{
	parse_special(tokens, input);
	if (!parse_commands(tokens, input))
		return (false);
	return (true);
}
