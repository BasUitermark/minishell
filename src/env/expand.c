/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/02 12:45:21 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/11/01 13:23:39 by jde-groo      ########   odam.nl         */
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

static bool	dodo_expand(char *location, char **expanded, unsigned int nv)
{
	if (ft_strncmp(&location[nv + 1], "?", 1) == 0)
	{
		if (!expand_exit_code(expanded))
			return (false);
	}
	else
	{
		if (get_env(g_shell.env, &location[nv + 1]))
			expanded[0] = ft_strappend(expanded[0], \
				get_env(g_shell.env, &location[nv + 1])->value);
	}
	return (true);
}

bool	do_expand(char *location, char **expanded, unsigned int *index)
{
	unsigned int	nv;
	unsigned int	vl;
	char			prev_char;

	if (!location[index[0]])
		return (false);
	nv = next_var(location, index[0]);
	if (!location[nv])
	{
		expanded[0] = ft_strappend(expanded[0], &location[index[0]]);
		return (false);
	}
	expanded[0] = ft_strnappendfree(expanded[0], \
		&location[index[0]], nv - index[0]);
	if (!expanded[0])
		return (false);
	vl = var_length(location, nv);
	prev_char = location[nv + vl];
	location[nv + vl] = 0;
	if (!dodo_expand(location, expanded, nv) || !expanded[0])
		return (false);
	location[nv + vl] = prev_char;
	index[0] += (nv - index[0]) + vl;
	return (true);
}
