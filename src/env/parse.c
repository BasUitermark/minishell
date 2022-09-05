/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/02 11:54:27 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/09/02 12:15:36 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/shell.h"

t_env	*parse_environment(char **envp)
{
	t_env	*env;

	env = NULL;
	if (!envp)
		return (NULL);
	while (*envp)
	{
		if (!add_variable(&env, *envp))
			return (clear_list(env));
		envp++;
	}
	return (env);
}