/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 16:00:11 by buiterma      #+#    #+#                 */
/*   Updated: 2022/08/24 15:27:06 by jde-groo      ########   odam.nl         */
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

# define SHELL BOLD BLUE "[mini_pain]> " RESET

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

int		main(void);

//======== Input Validation ========//
bool	validate_read(const char *input_line);


//======== Input Parsing ========//
bool	validate_read(const char *input_line);

#endif