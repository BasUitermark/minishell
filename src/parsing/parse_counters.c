/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_counters.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 10:47:52 by buiterma      #+#    #+#                 */
/*   Updated: 2022/08/31 16:16:12 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

size_t	command_counter(t_token *tokens)
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

size_t	arg_counter(t_token *tokens)
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
