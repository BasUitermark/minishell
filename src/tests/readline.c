/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   readline.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 15:34:46 by buiterma      #+#    #+#                 */
/*   Updated: 2022/08/23 18:04:07 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

bool	validate_read(const char *input_line)
{
	if (ft_strncmp(input_line, "exit", 4) == 0)
		return (false);
	return (true);
}

int	main(void)
{
	char	*input_line;

	while (validate_read(input_line))
	{
		input_line = readline("painshell$ "); // readline and "prompt"
		add_history(input_line); // readline history. Use up and down buttons.
	}
	free (input_line);
	input_line = NULL;
	return (0);
}
