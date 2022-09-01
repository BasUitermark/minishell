/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   post_processing.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 12:51:50 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/09/01 12:20:24 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

static void	find_expandable(const char *input, t_token *head)
{
	while (head)
	{
		if (input[head->index] != '\'' && head->type != PIPE)
			head->expandable = true;
		head = head->next;
	}
}

static void	find_adjacent(const char *input, t_token *head)
{
	while (head && head->next)
	{
		if (!ft_strchr("|<> ", input[head->index + head->length]) \
			&& input[head->index + head->length])
			head->adjacent = true;
		head = head->next;
	}
}

static void	remove_quotes(const char *input, t_token *head)
{
	while (head)
	{
		if ((input[head->index] == '"' || input[head->index] == '\'') \
			&& input[head->index + head->length - 1] == input[head->index])
		{
			head->index += 1;
			head->length -= 2;
		}
		head = head->next;
	}
}

t_token	*post_process(const char *input, t_token *head)
{
	find_expandable(input, head);
	find_adjacent(input, head);
	remove_quotes(input, head);
	return (head);
}
