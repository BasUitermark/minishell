/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utility.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/25 12:16:09 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/08/25 13:25:22 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/shell.h"

t_token	*init_token(void)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	ft_bzero(token, sizeof(token));
	return (token);
}

void	append_token(t_token *head, t_token *token)
{
	while (head)
		head = head->next;
	head = token;
}

void	lexer_cleanup(t_token *head)
{
	t_token	*next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
