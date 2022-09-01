/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   temp.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/01 10:59:09 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/09/01 12:01:56 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMP_H
# define TEMP_H

# include <stdbool.h>
# include <stdio.h>

typedef struct s_env {
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

s_env	*parse_environment(const char **envp);
bool	add_variable(s_env *head, char *var);
bool	remove_variable(s_env *head, char *key);

#endif