/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 16:00:11 by buiterma      #+#    #+#                 */
/*   Updated: 2022/08/24 17:26:17 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <stdlib.h>
# include "../libs/libft/include/libft.h"

# define SHELL "[mini_pain]> "
# define SPECIAL_CHAR "$|<>\'\""

typedef struct s_env {
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_command {
	char	*path;
	char	**args;
}	t_command;

typedef struct s_shell {
	t_env		*env;
	int			exit_code;
	int			fd_in;
	int			fd_out;
	int			pipe[2];
	pid_t		pid;
	t_command	*commands;
}	t_shell;

int			main(void);

//======== Input Validation ========//
bool		validate_read(const char *input_line);

//============ Parsing =============//
t_command	*parse_read(char *input);
t_command	parse_special(char *input);


//======== Input Parsing ========//
bool		resolve_paths(t_command *commands);

#endif