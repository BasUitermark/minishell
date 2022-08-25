/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 12:16:07 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/08/25 14:12:10 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/shell.h"

unsigned int	part_length(const char *input)
{
	unsigned int	length;
	char			end_of_line;

	length = 0;
	end_of_line = input[0];
	length++;
	if (end_of_line == '\"' || end_of_line == '\'')
	{
		while (input[length] && !(input[length] == \
			end_of_line && input[length - 1] != '\\'))
			length++;
		length++;
	}
	else
	{
		end_of_line = ' ';
		while (input[length] && (input[length] != end_of_line))
			length++;
	}
	return (length);
}

t_token	*lexer(const char *input)
{
	t_token	*head;

	head = init_token();
	if (!head)
		return (NULL);
	return (head);
}
