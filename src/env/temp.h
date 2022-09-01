/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   temp.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-groo <jde-groo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/01 10:59:09 by jde-groo      #+#    #+#                 */
/*   Updated: 2022/09/01 16:23:04 by jde-groo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMP_H
# define TEMP_H

# include "./../../libs/libft/include/libft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_env {
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

t_env	*parse_environment(char **envp);
t_env	*get_env(t_env *head, char *key);
bool	add_variable(t_env **head, char *var);
bool	remove_variable(t_env **head, char *key);

#endif