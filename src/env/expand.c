/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/02 12:45:21 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/09/05 12:16:33 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/shell.h"

static unsigned int	next_var(char *string, unsigned int from)
{
	while (string[from] && string[from + 1] && \
		!(string[from] == '$' && \
		(ft_isalpha(string[from + 1]) || string[from + 1] == '_')))
		from++;
	if (string[from] != '$')
		from++;
	return (from);
}

static unsigned int	var_length(char *string, unsigned int from)
{
	unsigned int	length;

	length = 1;
	while (string[from + length] && \
		(ft_isalnum(string[from + length]) || string[from + length] == '_'))
		length++;
	return (length);
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
	if (get_env(head, &location[index[0] + 1]))
		expanded[0] = ft_strappend(expanded[0], \
			get_env(head, &location[index[0] + 1])->value);
	if (!expanded[0])
		return (false);
	location[index[0] + var_length(location, index[0])] = prev_char;
	index[0] += var_length(location, index[0]);
	return (true);
}	

bool	expand(t_env *head, char **location)
{
	unsigned int	index;
	char			*expanded;
	char			prev_char;

	index = 0;
	expanded = NULL;
	while (location[0][index])
		if (!in_expand(head, location[0], &index, &expanded))
			return (false);
	expanded = ft_strnappend(expanded, &location[0][index], \
		next_var(location[0], index) - index);
	if (!expanded)
		return (false);
	location[0] = expanded;
	return (true);
}
