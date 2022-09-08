/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/02 12:45:21 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/09/08 18:28:45 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/shell.h"

static unsigned int	next_var(char *string, unsigned int from)
{
	while (string[from] && string[from + 1] && \
		!(string[from] == '$' && \
		(ft_isalpha(string[from + 1]) || string[from + 1] == '_' \
			|| string[from + 1] == '?')))
		from++;
	if (string[from] != '$')
		from++;
	return (from);
}

static unsigned int	var_length(char *string, unsigned int from)
{
	unsigned int	length;

	length = 1;
	if (string[from + length] == '?')
		return (2);
	while (string[from + length] && \
		(ft_isalnum(string[from + length]) || string[from + length] == '_'))
		length++;
	return (length);
}

static bool	expand_exit_code(char **expanded)
{
	char	*exit_code;

	exit_code = ft_itoa(g_shell.exit_code);
	if (!exit_code)
		return (false);
	expanded[0] = ft_strappend(expanded[0], exit_code);
	free(exit_code);
	return (true);
}

static bool	in_expand(t_env *head, char *location, \
	unsigned int *index, char **expanded)
{
	char	prev_char;

	expanded[0] = ft_strnappend(expanded[0], \
		&location[index[0]], next_var(location, index[0]) - index[0]);
	if (!expanded[0])
		return (false);
	index[0] = next_var(location, index[0]);
	prev_char = location[index[0] + var_length(location, index[0])];
	location[index[0] + var_length(location, index[0])] = 0;
	if (ft_strncmp(&location[index[0] + 1], "?", 1) == 0)
	{
		if (!expand_exit_code(expanded))
			return (false);
	}
	else
	{
		if (get_env(head, &location[index[0] + 1]))
			expanded[0] = ft_strappend(expanded[0], \
				get_env(head, &location[index[0] + 1])->value);
	}
	if (!expanded[0])
		return (false);
	location[index[0] + var_length(location, index[0])] = prev_char;
	index[0] += var_length(location, index[0]);
	return (true);
}

bool	expand(char **location)
{
	unsigned int	index;
	char			*expanded;
	char			prev_char;

	index = 0;
	expanded = NULL;
	while (location[0][index])
		if (!in_expand(g_shell.env, location[0], &index, &expanded))
			return (false);
	expanded = ft_strnappend(expanded, &location[0][index], \
		next_var(location[0], index) - index);
	if (!expanded)
		return (false);
	free(location[0]);
	location[0] = expanded;
	return (true);
}
