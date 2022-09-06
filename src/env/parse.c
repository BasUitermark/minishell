/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/02 11:54:27 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/09/06 11:24:18 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/shell.h"

bool	parse_environment(char **envp)
{
	if (!envp)
		return (false);
	while (*envp)
	{
		if (!add_variable(&g_shell.env, *envp))
			return (clear_list(&g_shell.env));
		envp++;
	}
	return (true);
}
