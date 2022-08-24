/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 11:29:47 by buiterma      #+#    #+#                 */
/*   Updated: 2022/08/24 16:44:27 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	count_args(char *input)
{
	int	i;
	int	count;
	int	left;
	int	right;

	i = 0;
	count = 0;
	right = 0;
	left = 0;
	while (input[i])
	{
		if (input[i] == '|')
			count++;
		if (input [i] == '<')
			left = 1;
		if (input [i] == '>')
			right = 1;
		i++;
	}
	if (!count && !left && !right)
		return (0);
	return (count + left + right + 1);
}

t_command	*parse_read(char *input)
{
	t_command	*data;
	int			i;
	int			arg;

	i = 0;
	arg = 0;
	printf("%d\n", count_args(input));
	// data = malloc(count_args(input) * sizeof(t_command));
	if (!data)
		free_array(input);
	while (input[i])
	{
		if (ft_strchr(SPECIAL_CHAR, input[i]))
		{
			data[arg] = parse_special(&input[i]);
			arg++;
		}
		else
		{
			data[arg] = parse_word();
			arg++;
		}
		i++;
	}
}
