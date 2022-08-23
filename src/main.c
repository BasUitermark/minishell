/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 20:43:40 by buiterma      #+#    #+#                 */
/*   Updated: 2022/08/23 21:18:48 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	main(void)
{
	char	*input_line;

	while (validate_read(input_line))
	{
		input_line = readline(SHELL); // readline and "prompt"
		add_history(input_line); // readline history. Use up and down buttons.
	}
	free (input_line);
	input_line = NULL;
	return (0);
}
