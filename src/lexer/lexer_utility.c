/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_utility.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 12:16:09 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/10/11 11:06:25 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

t_tokentype	get_type(const char *input, unsigned int from)
{
	if (ft_strncmp(&input[from], "<<", 2) == 0)
		return (HEREDOC);
	else if (ft_strncmp(&input[from], ">>", 2) == 0)
		return (OUTFILE_APPEND);
	else if (input[from] == '<')
		return (INFILE);
	else if (input[from] == '>')
		return (OUTFILE);
	else if (input[from] == '|')
		return (PIPE);
	else
		return (COMMAND);
}

unsigned int	find_next(const char *input, unsigned int from)
{
	while (input[from] && (input[from] == ' ' || input[from] == '\t'))
		from++;
	return (from);
}

bool	add_token(t_token **head, t_tokentype type, unsigned int index, \
	unsigned int length)
{
	t_token	*next;
	t_token	*last;

	next = ft_calloc(1, sizeof(t_token));
	if (!next)
		return (false);
	next->type = type;
	next->index = index;
	next->length = length;
	next->next = NULL;
	if (!*head)
		*head = next;
	else
	{
		last = *head;
		while (last->next)
			last = last->next;
		last->next = next;
	}
	return (true);
}

bool	part_handler(t_token **head, unsigned int index, unsigned int length, \
	t_tokentype type)
{
	if (type == PIPE)
		return (true);
	return (add_token(head, type, index, length));
}
